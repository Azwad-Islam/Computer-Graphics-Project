// Immediate-mode OpenGL (glBegin/glVertex/glEnd) for the web build.
//
// WebGL has no fixed-function pipeline, and Emscripten's LEGACY_GL_EMULATION
// draws this scene incorrectly. This header implements the small subset of
// old-style OpenGL that main.cpp uses on top of a WebGL shader: vertices are
// collected between glBegin and glEnd, converted to triangles (or lines) and
// drawn in one call. Desktop builds never include this file.
//
// Requires GL_GLEXT_PROTOTYPES (passed with -D in the build) so the GL 2.0
// shader and buffer functions are declared.
#pragma once

#include <vector>

namespace glcompat {

struct Vertex { float x, y, r, g, b, a; };

static float color[4] = { 1, 1, 1, 1 };
static GLenum matrixMode = GL_MODELVIEW;
static float ortho[4] = { -1, 1, -1, 1 }; // left, right, bottom, top
static GLenum primitive = GL_TRIANGLES;
static std::vector<Vertex> vertices;
static std::vector<Vertex> batch;
static GLuint program = 0, buffer = 0;
static GLint orthoUniform = -1;

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
        "varying vec4 v_col;\n"
        "void main() {\n"
        "  vec2 p = (pos - ortho.xz) / (ortho.yw - ortho.xz) * 2.0 - 1.0;\n"
        "  gl_Position = vec4(p, 0.0, 1.0);\n"
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
    glGenBuffers(1, &buffer);
}

static void begin(GLenum mode) {
    primitive = mode;
    vertices.clear();
}

static void vertex(float x, float y) {
    vertices.push_back({ x, y, color[0], color[1], color[2], color[3] });
}

static void end() {
    // Convert the primitive into plain triangles or lines
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
        drawMode = GL_LINES;
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
    // Only the projection matrix is ever changed (by gluOrtho2D)
    if (matrixMode == GL_PROJECTION) {
        ortho[0] = -1; ortho[1] = 1; ortho[2] = -1; ortho[3] = 1;
    }
}

static void ortho2D(double left, double right, double bottom, double top) {
    ortho[0] = (float)left; ortho[1] = (float)right;
    ortho[2] = (float)bottom; ortho[3] = (float)top;
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
