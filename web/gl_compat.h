// Immediate-mode OpenGL (glBegin/glVertex/glEnd) for the web build.
//
// WebGL has no fixed-function pipeline, and Emscripten's LEGACY_GL_EMULATION
// draws this scene incorrectly. This header implements the small subset of
// old-style OpenGL that main.cpp uses on top of a WebGL shader: vertices are
// collected between glBegin and glEnd, converted to triangles (or points) and
// drawn in one call. Desktop builds never include this file.
//
// Requires GL_GLEXT_PROTOTYPES (passed with -D in the build) so the GL 2.0
// shader and buffer functions are declared.
#pragma once

#include <cmath>
#include <vector>

namespace glcompat {

struct Vertex { float x, y, r, g, b, a; };

static float color[4] = { 1, 1, 1, 1 };
static GLenum matrixMode = GL_MODELVIEW;
static float ortho[4] = { -1, 1, -1, 1 }; // left, right, bottom, top
static float translation[2] = { 0, 0 };   // the modelview matrix only ever translates
static std::vector<float> matrixStack;
static float lineWidth = 1, pointSize = 1;
static GLenum primitive = GL_TRIANGLES;
static std::vector<Vertex> vertices;
static std::vector<Vertex> batch;
static GLuint program = 0, buffer = 0;
static GLint orthoUniform = -1, pointSizeUniform = -1;

static GLuint compile(GLenum type, const char* source) {
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);
    return shader;
}

static void init() {
    const char* vs =
        "attribute vec2 pos;\n"
        "attribute vec4 col;\n"
        "uniform vec4 ortho;\n"
        "uniform float pointSize;\n"
        "varying vec4 v_col;\n"
        "void main() {\n"
        "  vec2 p = (pos - ortho.xz) / (ortho.yw - ortho.xz) * 2.0 - 1.0;\n"
        "  gl_Position = vec4(p, 0.0, 1.0);\n"
        "  gl_PointSize = pointSize;\n"
        "  v_col = col;\n"
        "}\n";
    const char* fs =
        "precision mediump float;\n"
        "varying vec4 v_col;\n"
        "void main() { gl_FragColor = v_col; }\n";
    program = glCreateProgram();
    glAttachShader(program, compile(GL_VERTEX_SHADER, vs));
    glAttachShader(program, compile(GL_FRAGMENT_SHADER, fs));
    glBindAttribLocation(program, 0, "pos");
    glBindAttribLocation(program, 1, "col");
    glLinkProgram(program);
    orthoUniform = glGetUniformLocation(program, "ortho");
    pointSizeUniform = glGetUniformLocation(program, "pointSize");
    glGenBuffers(1, &buffer);
}

static void begin(GLenum mode) {
    primitive = mode;
    vertices.clear();
}

static void vertex(float x, float y) {
    vertices.push_back({ x + translation[0], y + translation[1], color[0], color[1], color[2], color[3] });
}

// Browsers only draw 1-pixel lines, so each line becomes a thin quad of the
// current line width (in pixels)
static void addLine(const Vertex& a, const Vertex& b) {
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    float unitsX = (ortho[1] - ortho[0]) / viewport[2]; // world units per pixel
    float unitsY = (ortho[3] - ortho[2]) / viewport[3];
    float dx = (b.x - a.x) / unitsX, dy = (b.y - a.y) / unitsY;
    float length = std::sqrt(dx * dx + dy * dy);
    if (length == 0) return;
    float half = (lineWidth < 1 ? 1 : lineWidth) / 2;
    float nx = -dy / length * half * unitsX, ny = dx / length * half * unitsY;
    Vertex a1 = a, a2 = a, b1 = b, b2 = b;
    a1.x += nx; a1.y += ny; a2.x -= nx; a2.y -= ny;
    b1.x += nx; b1.y += ny; b2.x -= nx; b2.y -= ny;
    batch.insert(batch.end(), { a1, b1, b2, a1, b2, a2 });
}

static void end() {
    // Convert the primitive into plain triangles (or points)
    batch.clear();
    GLenum drawMode = GL_TRIANGLES;
    size_t n = vertices.size();
    switch (primitive) {
    case GL_QUADS:
        for (size_t i = 0; i + 3 < n; i += 4) {
            const Vertex* q = &vertices[i];
            batch.insert(batch.end(), { q[0], q[1], q[2], q[0], q[2], q[3] });
        }
        break;
    case GL_POLYGON:
    case GL_TRIANGLE_FAN:
        for (size_t i = 1; i + 1 < n; i++)
            batch.insert(batch.end(), { vertices[0], vertices[i], vertices[i + 1] });
        break;
    case GL_LINES:
        for (size_t i = 0; i + 1 < n; i += 2)
            addLine(vertices[i], vertices[i + 1]);
        break;
    case GL_POINTS:
        drawMode = GL_POINTS;
        batch = vertices;
        break;
    default:
        batch = vertices;
        break;
    }
    if (batch.empty()) return;

    if (!program) init();
    glUseProgram(program);
    glUniform4f(orthoUniform, ortho[0], ortho[1], ortho[2], ortho[3]);
    glUniform1f(pointSizeUniform, pointSize);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, batch.size() * sizeof(Vertex), batch.data(), GL_STREAM_DRAW);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(2 * sizeof(float)));
    glDrawArrays(drawMode, 0, (GLsizei)batch.size());
}

static void setColor(float r, float g, float b, float a) {
    color[0] = r; color[1] = g; color[2] = b; color[3] = a;
}

static void loadIdentity() {
    if (matrixMode == GL_PROJECTION) {
        ortho[0] = -1; ortho[1] = 1; ortho[2] = -1; ortho[3] = 1;
    }
    else {
        translation[0] = translation[1] = 0;
    }
}

static void ortho2D(double left, double right, double bottom, double top) {
    ortho[0] = (float)left; ortho[1] = (float)right;
    ortho[2] = (float)bottom; ortho[3] = (float)top;
}

static void pushMatrix() {
    matrixStack.push_back(translation[0]);
    matrixStack.push_back(translation[1]);
}

static void popMatrix() {
    if (matrixStack.size() < 2) return;
    translation[1] = matrixStack.back(); matrixStack.pop_back();
    translation[0] = matrixStack.back(); matrixStack.pop_back();
}

} // namespace glcompat

#define glBegin(mode) glcompat::begin(mode)
#define glEnd() glcompat::end()
#define glVertex2f(x, y) glcompat::vertex((float)(x), (float)(y))
#define glColor3ub(r, g, b) glcompat::setColor((r) / 255.0f, (g) / 255.0f, (b) / 255.0f, 1.0f)
#define glColor4ub(r, g, b, a) glcompat::setColor((r) / 255.0f, (g) / 255.0f, (b) / 255.0f, (a) / 255.0f)
#define glMatrixMode(mode) (glcompat::matrixMode = (mode))
#define glLoadIdentity() glcompat::loadIdentity()
#define gluOrtho2D(l, r, b, t) glcompat::ortho2D((l), (r), (b), (t))
#define glPushMatrix() glcompat::pushMatrix()
#define glPopMatrix() glcompat::popMatrix()
#define glTranslatef(x, y, z) (glcompat::translation[0] += (float)(x), glcompat::translation[1] += (float)(y))
#define glLineWidth(w) (glcompat::lineWidth = (float)(w))
#define glPointSize(s) (glcompat::pointSize = (float)(s))
