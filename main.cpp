#include <iostream>
#include <GL/glut.h>
#include<GL/gl.h>
#include<math.h>
#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#include<mmsystem.h>
#endif

#ifdef __EMSCRIPTEN__
// Web build: provides glBegin/glVertex/glEnd on top of WebGL
#include "web/gl_compat.h"
#endif
using namespace std;

float blimpX = 2.19;
float blimpSpeed = 0.001;
bool blimpForward = true;
bool saveGotham = false;

void circle(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_POLYGON);
    for (int i = 0;i < 200;i++)
    {
        glColor3ub(r, g, b);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + xc, y + yc);
    }
    glEnd();
}

void drawEllipse(float centerX, float centerY, float radiusX, float radiusY, int segments, float red, float green, float blue) {

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(red, green, blue);
    glVertex2f(centerX, centerY);
    for (int i = 0; i <= segments; ++i) {
        float theta = 2.0f * 3.1415926f * float(i) / float(segments);
        float x = radiusX * cosf(theta);
        float y = radiusY * sinf(theta);
        glVertex2f(x + centerX, y + centerY);
    }
    glEnd();
}

void sky() {
    glBegin(GL_QUADS);
    glColor3ub(11, 27, 43);
    glVertex2f(-6, 0);
    glVertex2f(6, 0);
    glVertex2f(6, 17);
    glVertex2f(-6, 17);
    glEnd();
}

void buldingBehindBuildinginfrontbatman() {
    //Front side
    glBegin(GL_QUADS);
    glColor3ub(29, 28, 34);
    glVertex2f(-4.08255, 8.14627);
    glVertex2f(-4.07748, 7.23953);
    glVertex2f(-2.11901, 7.13937);
    glVertex2f(-2.11464, 8.10044);
    glEnd();
    //Back side
    glBegin(GL_QUADS);
    glColor3ub(38, 30, 35);
    glVertex2f(-2.11464, 8.2);
    glVertex2f(-2.10132, 6.27561);
    glVertex2f(-1.17721, 6.37343);
    glVertex2f(-1.18285, 8.16891);
    glEnd();
    //ledge
    glBegin(GL_QUADS);
    glColor3ub(60, 40, 41);
    glVertex2f(-4.23809, 8.15079);
    glVertex2f(-2.11464, 8.10044);
    glVertex2f(-2.11228, 8.26335);
    glVertex2f(-4.23497, 8.31885);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(60, 40, 41);
    glVertex2f(-2.11464, 8.10044);
    glVertex2f(-1.06261, 8.18947);
    glVertex2f(-1.06261, 8.3403);
    glVertex2f(-2.11228, 8.26335);
    glEnd();
    //box
    glBegin(GL_POLYGON);
    glColor3ub(70, 49, 49);
    glVertex2f(-3.6, 8.3);
    glVertex2f(-3.07, 8.29);
    glVertex2f(-3.06576, 8.55077);
    glVertex2f(-3.6001, 8.55846);
    glEnd();
    //roof
    glBegin(GL_POLYGON);
    glColor3ub(38, 30, 35);
    glVertex2f(-4.23497, 8.31885);
    glVertex2f(-2.11228, 8.26335);
    glVertex2f(-1.06261, 8.3403);
    glVertex2f(-2.03134, 8.36676);
    glVertex2f(-3.31588, 8.3813);
    glEnd();
    //add missing windows
}

void npcBuildings() {
    //1st building
    glBegin(GL_POLYGON);
    glColor3ub(9, 16, 27);
    glVertex2f(3.7, 9.7);
    glVertex2f(4.09292, 9.69558);
    glVertex2f(4.09469, 10.06352);
    glVertex2f(3.69844, 10.06883);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(9, 16, 27);
    glVertex2f(4.01, 10.06);
    glVertex2f(4.01159, 10.09184);
    glVertex2f(3.76114, 10.09538);
    glVertex2f(3.76114, 10.07);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(9, 16, 27);
    glVertex2f(3.96, 10.09);
    glVertex2f(3.96461, 10.15491);
    glVertex2f(3.78603, 10.15815);
    glVertex2f(3.78603, 10.12623);
    glVertex2f(3.7606, 10.12623);
    glVertex2f(3.76114, 10.09538);
    glEnd();
    //windows
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(177, 177, 177); // Building rgb(177, 177, 177)
    glVertex2f(3.77253, 9.96882);
    glVertex2f(3.77253, 10.05585);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(177, 177, 177); // Building rgb(177, 177, 177)
    glVertex2f(3.86135, 9.96882);
    glVertex2f(3.86135, 10.05585);
    glEnd();

    //2
    glBegin(GL_POLYGON);
    glColor3ub(46, 35, 32);
    glVertex2f(3.6, 8.7);
    glVertex2f(3.9, 8.7);
    glVertex2f(3.91426, 9.93144);
    glVertex2f(3.60208, 9.96963);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(46, 35, 32);
    glVertex2f(3.18715, 8.7);
    glVertex2f(3.6, 8.7);
    glVertex2f(3.6, 9.93);
    glVertex2f(3.18, 9.93);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(46, 35, 32);
    glVertex2f(3.15421, 9.93);
    glVertex2f(3.6, 9.93);
    glVertex2f(3.60208, 9.969);
    glVertex2f(3.15558, 9.969);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(46, 35, 32);
    glVertex2f(3.53157, 10.01913);//o2
    glVertex2f(3.5302, 10.06498);//n2
    glVertex2f(3.37691, 10.06498);//m2
    glVertex2f(3.38, 9.97);//l2
    glVertex2f(3.59, 9.97);//q2
    glVertex2f(3.59522, 10.01913);//p2
    glEnd();

    //windows
    //1st floor
    for (float i = 3.20726; i <= 3.5; i += 0.0413200000)
    {
        glLineWidth(1.4);
        glBegin(GL_LINES);
        glColor3ub(191, 175, 128); // Building rgb(191, 175, 128)
        glVertex2f(i, 9.76015);
        glVertex2f(i, 9.89546);
        glEnd();
    }

    //Middle building covering empty space
//Missing window
    glBegin(GL_POLYGON);
    glColor3ub(9, 16, 27);
    glVertex2f(0.26, 7.56);
    glVertex2f(2.29124, 7.53613);
    glVertex2f(2.29844, 3.31215);
    glVertex2f(0.26382, 4.75525);
    glEnd();
    //roof
    glBegin(GL_POLYGON);
    glColor3ub(9, 16, 27);
    glVertex2f(0.26, 7.56);
    glVertex2f(2.29124, 7.53613);
    glVertex2f(2.58239, 7.82382);
    glVertex2f(1.02251, 7.87171);
    glEnd();

    //3rd building 
    glBegin(GL_POLYGON);
    glColor3ub(9, 16, 27);
    glVertex2f(3.08383, 8.57307);
    glVertex2f(3.23353, 8.65178);
    glVertex2f(3.23662, 9.35863);
    glVertex2f(3.08537, 9.36017);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(9, 16, 27);
    glVertex2f(2.5236, 8.56381);
    glVertex2f(3.08383, 8.57307);
    glVertex2f(3.08537, 9.36017);
    glVertex2f(2.52977, 9.36171);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(9, 16, 27);
    glVertex2f(2.85233, 9.36);
    glVertex2f(3, 9.36);
    glVertex2f(2.99432, 9.4574);
    glVertex2f(2.85387, 9.46049);
    glEnd();
    // windows
    glPointSize(3);
    glColor3ub(255, 248, 148);
    glBegin(GL_POINTS);
    glVertex2f(2.81162, 9.13532);
    glVertex2f(2.6223, 9.13237);
    glVertex2f(2.95065, 9.1368);
    glVertex2f(2.81162, 9.13532 - 0.10797);
    glVertex2f(2.6223, 9.13237 - 0.10797); //9.02735
    glVertex2f(2.95065, 9.1368 - 0.10797);
    glVertex2f(2.81162, 9.02735 - 0.10797);
    glVertex2f(2.6223, 9.02735 - 0.10797); //8.91938
    glVertex2f(2.95065, 9.02735 - 0.10797);
    glVertex2f(2.81162, 8.91938 - 0.10797);
    glVertex2f(2.6223, 8.91938 - 0.10797); //8.91938
    glVertex2f(2.95065, 8.91938 - 0.10797);
    glVertex2f(2.81162, 8.81141 - 0.10797);
    glVertex2f(2.6223, 8.81141 - 0.10797); //8.91938
    glVertex2f(2.95065, 8.81141 - 0.10797);
    glEnd();

    //2nd building
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(191, 175, 128); // Building rgb(191, 175, 128)
    glVertex2f(3.24777, 9.61592);
    glVertex2f(3.24777, 9.73908);
    glEnd();
    glLineWidth(0.8);
    glBegin(GL_LINES);
    glColor3ub(191, 175, 128); // Building rgb(191, 175, 128)
    glVertex2f(3.31905, 9.61592);
    glVertex2f(3.31905, 9.73908);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(191, 175, 128); // Building rgb(191, 175, 128)
    glVertex2f(3.39928, 9.61592);
    glVertex2f(3.39928, 9.73908);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(191, 175, 128); // Building rgb(191, 175, 128)
    glVertex2f(3.47808, 9.61592);
    glVertex2f(3.47808, 9.73908);
    glEnd();

    //3rd floor
    for (float i = 3.25227; i <= 3.5; i += 0.0413200000)
    {
        glLineWidth(1.4);
        glBegin(GL_LINES);
        glColor3ub(191, 175, 128); // Building rgb(191, 175, 128)
        glVertex2f(i, 9.4723);
        glVertex2f(i, 9.58735);
        glEnd();
    }

    //4rd floor
    for (float i = 3.28; i <= 3.5; i += 0.1073)
    {
        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3ub(191, 175, 128); // Building rgb(191, 175, 128)
        glVertex2f(i, 9.31632);
        glVertex2f(i, 9.45129);
        glEnd();
    }
    //5h floor
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3ub(191, 175, 128); // Building rgb(191, 175, 128)
    glVertex2f(3.29913, 9.17282);
    glVertex2f(3.29913, 9.3);
    glEnd();
    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3ub(191, 175, 128); // Building rgb(191, 175, 128)
    glVertex2f(3.33433, 9.17282);
    glVertex2f(3.33433, 9.3);
    glEnd();

    glLineWidth(1.7);
    glBegin(GL_LINES);
    glColor3ub(191, 175, 128); // Building rgb(191, 175, 128)
    glVertex2f(3.39928, 9.17282);
    glVertex2f(3.39928, 9.3);
    glEnd();

    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3ub(191, 175, 128); // Building rgb(191, 175, 128)
    glVertex2f(3.36048, 9.17282);
    glVertex2f(3.36048, 9.3);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(191, 175, 128); // Building rgb(191, 175, 128)
    glVertex2f(3.47613, 9.17282);
    glVertex2f(3.47613, 9.3);
    glEnd();
    glLineWidth(0.8);
    glBegin(GL_LINES);
    glColor3ub(191, 175, 128); // Building rgb(191, 175, 128)
    glVertex2f(3.42484, 9.17282);
    glVertex2f(3.42484, 9.3);
    glEnd();

    //6th floor
    for (float i = 3.26315; i <= 3.5; i += 0.0016200000)
    {
        glLineWidth(1);
        glBegin(GL_LINES);
        glColor3ub(167, 162, 113); // Building rgb(167, 162, 113)
        glVertex2f(i, 9.02687);
        glVertex2f(i, 9.15023);
        glEnd();
    }
    //7th floor
    for (float i = 3.22; i <= 3.5; i += 0.0016200000)
    {
        glLineWidth(1);
        glBegin(GL_LINES);
        glColor3ub(160, 157, 88); // Building rgb(160, 157, 88)
        glVertex2f(i, 8.88134);
        glVertex2f(i, 9.00085);
        glEnd();
    }
    //8th floor
    for (float i = 3.21; i <= 3.5; i += 0.0016200000)
    {
        glLineWidth(1);
        glBegin(GL_LINES);
        glColor3ub(213, 199, 113); // Building rgb(213, 199, 113)
        glVertex2f(i, 8.71557);
        glVertex2f(i, 8.86013);
        glEnd();
    }

    //Side windows
    //8th
    glBegin(GL_QUADS);
    glColor3ub(213, 199, 113); //    rgb(152, 159, 84)
    glVertex2f(3.62887, 8.71616);
    glVertex2f(3.84421, 8.72385);
    glVertex2f(3.84644, 8.84833);
    glVertex2f(3.63079, 8.84498);
    glEnd();
    //7th
    glBegin(GL_POLYGON);
    glColor3ub(152, 159, 84); //    rgb(152, 159, 84)
    glVertex2f(3.62983, 8.86997);
    glVertex2f(3.85478, 8.87766);
    glVertex2f(3.85863, 9.00456);
    glVertex2f(3.63368, 9.0036);
    glEnd();
    //1st
    glBegin(GL_QUADS);
    glColor3ub(191, 175, 128); //    rgb(191, 175, 128)
    glVertex2f(3.6231, 9.89763);
    glVertex2f(3.61926, 9.75535);
    glVertex2f(3.899, 9.74093);
    glVertex2f(3.899, 9.8736);
    glEnd();

    //4th
    glBegin(GL_QUADS);
    glColor3ub(191, 175, 128); //    rgb(191, 175, 128)
    glVertex2f(3.63175, 9.30449);
    glVertex2f(3.86343, 9.30738);
    glVertex2f(3.86536, 9.441);
    glVertex2f(3.63368, 9.43908);
    glEnd();
}

void Batman() {
    //ears
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(-2.80023, 11.52965);
    glVertex2f(-2.9167, 11.04715);
    glVertex2f(-2.69428, 11.2895);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(-2.25283, 11.53537);
    glVertex2f(-2.41775, 11.29193);
    glVertex2f(-2.11756, 11.04414);
    glEnd();

    //head
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(-2.41775, 11.29193);
    glVertex2f(-2.69428, 11.2895);
    glVertex2f(-2.9167, 11.04715);
    glVertex2f(-2.11756, 11.04414);
    glEnd();
    //body
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(-2.11756, 11.04414);
    glVertex2f(-2.9167, 11.04715);
    glVertex2f(-3.54039, 10.58904);
    glVertex2f(-1.60743, 10.55441);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(-1.60743, 10.55441);
    glVertex2f(-3.54039, 10.58904);
    glVertex2f(-3.9962, 7.60101);
    glVertex2f(-1.27121, 7.64028);
    glEnd();

    //cape bottom
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(-3.9962, 7.60101);
    glVertex2f(-4.12707, 7.2997);
    glVertex2f(-3.8, 7.6);
    glEnd();
    //2
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(-3.8, 7.6);
    glVertex2f(-3.66552, 7.28612);
    glVertex2f(-3.5343, 7.60287);
    glEnd();
    //3
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(-3.5241, 7.6234);
    glVertex2f(-3.28091, 7.30422);
    glVertex2f(-3.07276, 7.62097);
    glEnd();
    //4
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(-3.07276, 7.62097);
    glVertex2f(-2.89177, 7.29065);
    glVertex2f(-2.59312, 7.63002);
    glEnd();

    //5
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(-2.59312, 7.63002);
    glVertex2f(-2.4257, 7.29517);
    glVertex2f(-2.13158, 7.62549);
    glEnd();

    //6
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(-2.13158, 7.62549);
    glVertex2f(-1.86009, 7.29065);
    glVertex2f(-1.65647, 7.63002);
    glEnd();

    //7
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(-1.65647, 7.63002);
    glVertex2f(-1.18588, 7.27707);
    glVertex2f(-1.27121, 7.64028);
    glEnd();
}

void policeBlimp() {
    glPushMatrix();
    glTranslatef(blimpX, 0, 0);
    drawEllipse(2.19, 14.51, 0.75, 0.32, 100, 57, 52, 57);

    glBegin(GL_QUADS);
    glColor3ub(172, 151, 54); // Solid color at the bottom 
    glVertex2f(2.12859, 14.08628);
    glColor3ub(80, 72, 40); // Semi-transparent color at the top
    glVertex2f(2.31533, 10.89752);
    glColor3ub(80, 72, 40); // Semi-transparent color at the top
    glVertex2f(3.98194, 11.23578);
    glColor3ub(172, 151, 54); // Solid color at the bottom 
    glVertex2f(2.31181, 14.08628);
    glEnd();

    //box
    glBegin(GL_QUADS);
    glColor3ub(71, 66, 72);
    glVertex2f(1.96175, 14.07416);
    glVertex2f(2.31214, 14.07416);
    glVertex2f(2.32, 14.21);
    glVertex2f(1.94, 14.21);
    glEnd();

    //glass
    glBegin(GL_QUADS);
    glColor3ub(88, 96, 104);
    glVertex2f(1.99719, 14.1616);
    glVertex2f(1.99962, 14.12766);
    glVertex2f(2.31356, 14.12766);
    glVertex2f(2.31356, 14.1616);
    glEnd();
    glPopMatrix();

}

void Buildinginfrontbatman() {
    //roof
    glBegin(GL_QUADS);
    glColor3ub(55, 37, 39);
    glVertex2f(-0.6121, 5.45109);
    glVertex2f(-1.8552, 4.83867);
    glVertex2f(0.09197, 4.49217);
    glVertex2f(1.40941, 5.26535);
    glEnd();
    //front
    glBegin(GL_QUADS);
    glColor3ub(31, 31, 36);
    glVertex2f(0.09197, 4.49217);
    glVertex2f(-1.41, 4.76);
    glVertex2f(-1.40174, 3.24704);
    glVertex2f(0.09639, 3.02589);
    glEnd();

    //WINDOW 1
    glBegin(GL_QUADS);
    glColor3ub(209, 147, 69);
    glVertex2f(-1.00879, 4.43414);
    glVertex2f(-1.33, 4.47);
    glVertex2f(-1.32, 3.98);
    glVertex2f(-1.01223, 3.95525);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(-1.17, 4.45);
    glVertex2f(-1.17, 3.8);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(-1.33, 4.23);
    glVertex2f(-1, 4.21);
    glEnd();

    //WINDOW 2
    glBegin(GL_QUADS);
    glColor3ub(206, 145, 71);
    glVertex2f(0.00604, 4.34053);
    glVertex2f(-0.29669, 4.37264);
    glVertex2f(-0.31504, 3.85892);
    glVertex2f(0.01062, 3.8314);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(-0.15, 4.36);
    glVertex2f(-0.15, 3.85);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(-0.31, 4.12);
    glVertex2f(0.1, 4.08);
    glEnd();

    //WINDOW 3
    glBegin(GL_QUADS);
    glColor3ub(197, 121, 66);
    glVertex2f(-0.51686, 3.72591);
    glVertex2f(-0.815, 3.75801);
    glVertex2f(-0.82417, 3.25806);
    glVertex2f(-0.50768, 3.22136);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(-0.82, 3.51);
    glVertex2f(-0.51, 3.48);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(-0.66, 3.74);
    glVertex2f(-0.67, 3.24);
    glEnd();

    //side
    glBegin(GL_QUADS);
    glColor3ub(32, 29, 35);
    glVertex2f(0.09197, 4.49217);
    glVertex2f(0.09639, 3.02589);
    glVertex2f(1.44491, 4.03971);
    glVertex2f(1.40941, 5.26535);
    glEnd();

    //windows4
    glBegin(GL_QUADS);
    glColor3ub(212, 155, 78);
    glVertex2f(0.43719, 4.51942);
    glVertex2f(0.2262, 4.3864);
    glVertex2f(0.22161, 3.9002);
    glVertex2f(0.44178, 4.03781);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(0.34, 4.46);
    glVertex2f(0.35, 3.9);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(0.44, 4.28);
    glVertex2f(0.22, 4.15);
    glEnd();

    //windows5
    glBegin(GL_QUADS);
    glColor3ub(222, 173, 109);
    glVertex2f(1.07098, 4.90999);
    glVertex2f(0.9, 4.8);
    glVertex2f(0.89231, 4.33075);
    glVertex2f(1.08827, 4.44459);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(0.98, 4.85);
    glVertex2f(0.99, 4.39);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(1.08219, 4.68478);
    glVertex2f(0.8, 4.57);
    glEnd();

    //windows6
    glBegin(GL_QUADS);
    glColor3ub(215, 168, 107);
    glVertex2f(1.35484, 5.08002);
    glVertex2f(1.18049, 4.97051);
    glVertex2f(1.18481, 4.52239);
    glVertex2f(1.36492, 4.64055);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(1.27, 5.03);
    glVertex2f(1.28365, 4.58267);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(1.36, 4.86);
    glVertex2f(1.18, 4.75);
    glEnd();

    //windows7
    glBegin(GL_QUADS);
    glColor3ub(203, 138, 64);
    glVertex2f(0.43735, 3.87304);
    glVertex2f(0.22423, 3.723);
    glVertex2f(0.22423, 3.23539);
    glVertex2f(0.4561, 3.38543);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(0.34, 3.8);
    glVertex2f(0.35, 3.32);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(0.45, 3.63);
    glVertex2f(0.22, 3.49);
    glEnd();

    //windows8
    glBegin(GL_QUADS);
    glColor3ub(205, 152, 82);
    glVertex2f(1.07158, 4.30438);
    glVertex2f(0.89427, 4.18504);
    glVertex2f(0.89427, 3.72641);
    glVertex2f(1.07499, 3.8594);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(0.99, 4.25);
    glVertex2f(1, 3.81);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(1.07, 4.09);
    glVertex2f(0.89, 3.97);
    glEnd();

    //balcony
    glBegin(GL_QUADS);
    glColor3ub(28, 27, 32);
    glVertex2f(-1.31127, 2.95822);
    glVertex2f(-1.31127, 2.71767);
    glVertex2f(0.16809, 2.46);
    glVertex2f(0.16628, 2.76324);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(42, 31, 30);
    glVertex2f(-0.88, 3.18);
    glVertex2f(-1.31127, 2.95822);
    glVertex2f(0.16628, 2.76324);
    glVertex2f(0.09639, 3.02589);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(29, 28, 32);
    glVertex2f(-1.4, 3.24704);
    glVertex2f(-1.4, 2.95822);
    glVertex2f(-0.88, 3.18);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(27, 26, 30);
    glVertex2f(0.16628, 2.76324);
    glColor3ub(68, 41, 40);
    glVertex2f(0.16809, 2.50719);
    glVertex2f(2.15261, 4.01663);
    glVertex2f(2.15098, 4.2764);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(56, 37, 34);
    glVertex2f(2.15098, 4.2764);
    glVertex2f(1.43674, 4.35793);
    glVertex2f(1.44, 4.25);
    glVertex2f(2.02, 4.17);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(28, 28, 32);
    glVertex2f(0.09639, 3.02589);
    glVertex2f(-1.4, 3.24704);
    glVertex2f(-1.4, 2.65);
    glVertex2f(0.16628, 2.76324);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(84, 46, 41);
    glVertex2f(2.02, 4.17);
    glVertex2f(1.44491, 4.03971);
    glColor3ub(38, 33, 33);
    glVertex2f(0.09639, 3.02589);
    glVertex2f(0.16628, 2.76324);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(109, 59, 45);
    glVertex2f(2.02, 4.17);
    glColor3ub(55, 37, 36);
    glVertex2f(1.44, 4.25);
    glVertex2f(1.44491, 4.03971);
    glEnd();

    //botom front
    glBegin(GL_QUADS);
    glColor3ub(15, 23, 35);
    glVertex2f(0.16809, 2.50719);
    glVertex2f(-1.4175, 2.73);
    glColor3ub(72, 47, 45);
    glVertex2f(-1.6, 0);
    glVertex2f(0.1887, 0);
    glEnd();

    //window1
    glBegin(GL_QUADS);
    glColor3ub(164, 75, 57);
    glVertex2f(-0.65765, 1.95373);
    glVertex2f(-1, 2);
    glVertex2f(-1.01285, 1.52398);
    glVertex2f(-0.64449, 1.47575);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(-0.82, 1.98);
    glVertex2f(-0.83, 1.5);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(-0.65, 1.71);
    glVertex2f(-1.01, 1.76);
    glEnd();

    //window2
    glBegin(GL_QUADS);
    glColor3ub(190, 121, 63);
    glVertex2f(-0.03635, 1.86102);
    glVertex2f(-0.39449, 1.90923);
    glVertex2f(-0.40531, 1.41419);
    glVertex2f(-0.03088, 1.36268);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(-0.22, 1.89);
    glVertex2f(-0.22574, 1.36145);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(-0.4, 1.67);
    glVertex2f(-0.03, 1.61);
    glEnd();

    //window3
    glBegin(GL_QUADS);
    glColor3ub(213, 163, 68);
    glVertex2f(-0.03707, 1.19805);
    glVertex2f(-0.40472, 1.25389);
    glVertex2f(-0.41403, 0.76291);
    glVertex2f(-0.03009, 0.70707);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(-0.22, 1.23);
    glVertex2f(-0.22, 0.7);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(-0.03, 0.95);
    glVertex2f(-0.41577, 1.00216);
    glEnd();

    //window4
    glBegin(GL_QUADS);
    glColor3ub(223, 162, 73);
    glVertex2f(-0.64888, 0.65646);
    glVertex2f(-1.00175, 0.72042);
    glVertex2f(-1.00836, 0.23963);
    glVertex2f(-0.64667, 0.17127);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(-0.82, 0.69);
    glVertex2f(-0.83, 0.21);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(-0.65, 0.41);
    glVertex2f(-1.01, 0.48);
    glEnd();

    //side
    glBegin(GL_QUADS);
    glColor3ub(57, 38, 35);
    glVertex2f(2.02, 3.92);
    glColor3ub(30, 38, 41);
    glVertex2f(0.16569, 2.55);
    glColor3ub(107, 65, 53);
    glVertex2f(0.18, -0.00055);
    glVertex2f(2, -0.00055);
    glEnd();

    //window1
    glBegin(GL_QUADS);
    glColor3ub(165, 114, 56);
    glVertex2f(0.55564, 2.0934);
    glVertex2f(0.35586, 1.91104);
    glVertex2f(0.36006, 1.39908);
    glVertex2f(0.57487, 1.60126);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(0.47, 2.02);
    glVertex2f(0.49, 1.52);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(0.58711, 1.86384);
    glVertex2f(0.34934, 1.66246);
    glEnd();

    //window2
    glBegin(GL_QUADS);
    glColor3ub(211, 170, 72);
    glVertex2f(0.60857, 1.45383);
    glVertex2f(0.35586, 1.23276);
    glVertex2f(0.35584, 0.72514);
    glVertex2f(0.62121, 0.96944);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(0.49, 1.35);
    glVertex2f(0.5, 0.86);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(0.62, 1.2);
    glVertex2f(0.35, 0.98);
    glEnd();

    //window3
    glBegin(GL_QUADS);
    glColor3ub(206, 162, 60);
    glVertex2f(0.6, 0.8);
    glVertex2f(0.35095, 0.54956);
    glVertex2f(0.36006, 0.01751);
    glVertex2f(0.61278, 0.28287);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(0.48, 0.68);
    glVertex2f(0.5, 0.15);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(30, 32, 38);
    glVertex2f(0.61, 0.55);
    glVertex2f(0.35, 0.29);
    glEnd();

}

void buildingBeforeverticleWindows() {
    //roof
    glBegin(GL_QUADS);
    glColor3ub(101, 58, 48);
    glVertex2f(6.00066, 6.82114);
    glVertex2f(5.32053, 6.85204);
    glVertex2f(4.91182, 6.50363);
    glVertex2f(5.99537, 6.45543);
    glEnd();
    //front
    glBegin(GL_QUADS);
    glColor3ub(27, 24, 28);
    glVertex2f(5.99537, 6.45543);
    glVertex2f(4.91182, 6.50363);
    glVertex2f(4.97154, 4.33331);
    glVertex2f(6.00122, 4.22725);
    glEnd();
    //window1
    glBegin(GL_QUADS);
    glColor3ub(216, 155, 68);
    glVertex2f(5.58879, 6.06626);
    glVertex2f(5.42083, 6.07059);
    glVertex2f(5.41845, 5.76085);
    glVertex2f(5.58879, 5.75448);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.42, 6);
    glVertex2f(5.59, 6);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.42, 5.91);
    glVertex2f(5.59, 5.91);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.42, 5.83);
    glVertex2f(5.59, 5.83);
    glEnd();
    //verticle
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.48, 6.07);
    glVertex2f(5.48, 5.7);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.55, 6.07);
    glVertex2f(5.55, 5.7);
    glEnd();

    //window2
    glBegin(GL_QUADS);
    glColor3ub(210, 150, 63);
    glVertex2f(6, 6.05);
    glVertex2f(5.83549, 6.05498);
    glVertex2f(5.83448, 5.72331);
    glVertex2f(6, 5.72);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.84, 5.97);
    glVertex2f(6, 5.97);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.83, 5.89);
    glVertex2f(6, 5.89);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.83, 5.83);
    glVertex2f(6, 5.83);
    glEnd();
    //verticle
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.9, 6.05);
    glVertex2f(5.89, 5.72);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.96, 6.07);
    glVertex2f(5.96, 5.7);
    glEnd();

    //3rd window
    glBegin(GL_QUADS);
    glColor3ub(197, 111, 51);
    glVertex2f(5.17133, 5.72185);
    glVertex2f(5.00362, 5.72065);
    glVertex2f(5.00482, 5.41278);
    glVertex2f(5.17253, 5.41278);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.16773, 5.64039);
    glVertex2f(5, 5.64);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.00122, 5.56252);
    glVertex2f(5.17, 5.56);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5, 5.48);
    glVertex2f(5.17, 5.48);
    glEnd();
    //verticle
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.12, 5.72);
    glVertex2f(5.12, 5.4);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.06, 5.72);
    glVertex2f(5.06, 5.4);
    glEnd();

    //4th window
    glBegin(GL_QUADS);
    glColor3ub(198, 120, 54);
    glVertex2f(5.58688, 5.68345);
    glVertex2f(5.42561, 5.68833);
    glVertex2f(5.42381, 5.39291);
    glVertex2f(5.58369, 5.386);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.58, 5.61);
    glVertex2f(5.4, 5.62);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.58476, 5.53134);
    glVertex2f(5.4, 5.54);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.42096, 5.46);
    glVertex2f(5.58369, 5.45);
    glEnd();
    //verticle
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.48, 5.69);
    glVertex2f(5.48, 5.39);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.55, 5.69);
    glVertex2f(5.54434, 5.38348);
    glEnd();

    //5th window
    glBegin(GL_QUADS);
    glColor3ub(174, 105, 49);
    glVertex2f(5.80282, 5.67387);
    glVertex2f(5.63817, 5.67752);
    glVertex2f(5.63457, 5.3767);
    glVertex2f(5.80175, 5.36434);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.8, 5.6);
    glVertex2f(5.62, 5.61);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.80069, 5.51645);
    glVertex2f(5.63, 5.52);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.8, 5.44);
    glVertex2f(5.64, 5.44);
    glEnd();
    //verticle
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.69, 5.68);
    glVertex2f(5.68, 5.37);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.75, 5.68);
    glVertex2f(5.75, 5.37);
    glEnd();

    //6th window
    glBegin(GL_QUADS);
    glColor3ub(171, 73, 41);
    glVertex2f(5.3769, 5.32453);
    glVertex2f(5.21626, 5.32874);
    glVertex2f(5.2099, 5.02481);
    glVertex2f(5.37763, 5.01825);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.38, 5.25);
    glVertex2f(5.21, 5.26);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.2099, 5.17212);
    glVertex2f(5.38, 5.17);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.21, 5.09);
    glVertex2f(5.38, 5.09);
    glEnd();
    //verticle
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.27, 5.33);
    glVertex2f(5.26824, 5.02);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.32804, 5.32817);
    glVertex2f(5.33, 5.02);
    glEnd();

    //7th window
    glBegin(GL_QUADS);
    glColor3ub(171, 73, 41);
    glVertex2f(5.8159, 5.30378);
    glVertex2f(5.62862, 5.30249);
    glVertex2f(5.62345, 4.98347);
    glVertex2f(5.81073, 4.98476);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.63, 5.22);
    glVertex2f(5.81, 5.22);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.63, 5.14);
    glVertex2f(5.81, 5.14);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.62, 5.06);
    glVertex2f(5.81, 5.06);
    glEnd();
    //verticle
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.68, 5.3);
    glVertex2f(5.68, 4.98);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.75, 5.32817);
    glVertex2f(5.75261, 4.98217);
    glEnd();

    //8th window
    glBegin(GL_QUADS);
    glColor3ub(171, 73, 41);
    glVertex2f(5.58376, 4.93316);
    glVertex2f(5.41422, 4.93815);
    glVertex2f(5.41405, 4.63767);
    glVertex2f(5.58043, 4.63002);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.41, 4.87);
    glVertex2f(5.59, 4.86);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.41, 4.78);
    glVertex2f(5.59, 4.78);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.41, 4.71);
    glVertex2f(5.58, 4.71);
    glEnd();
    //verticle
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.48, 4.94);
    glVertex2f(5.48, 4.63);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.54, 4.93);
    glVertex2f(5.53698, 4.62658);
    glEnd();

    //9th window
    glBegin(GL_QUADS);
    glColor3ub(129, 55, 35);
    glVertex2f(5.16774, 4.97713);
    glVertex2f(5.018, 4.97866);
    glVertex2f(5.01559, 4.66269);
    glVertex2f(5.17385, 4.66236);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.02, 4.9);
    glVertex2f(5.17, 4.9);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.02, 4.8);
    glVertex2f(5.17, 4.8);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.02, 4.74);
    glVertex2f(5.17966, 4.73473);
    glEnd();
    //verticle
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.06, 4.98);
    glVertex2f(5.06, 4.66);
    glEnd();
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(27, 24, 28);
    glVertex2f(5.12, 4.98);
    glVertex2f(5.11936, 4.65646);
    glEnd();


}

void buildingAboveBottomRight() {
    //roof
    glBegin(GL_QUADS);
    glColor3ub(56, 37, 31);
    glVertex2f(6.00122, 4.22725);
    glVertex2f(4.97154, 4.33331);
    glVertex2f(4.46333, 3.63507);
    glVertex2f(6.00122, 3.44946);
    glEnd();

    //front
    glBegin(GL_QUADS);
    glColor3ub(22, 20, 23);
    glVertex2f(6.00122, 3.44946);
    glVertex2f(4.46333, 3.63507);
    glVertex2f(4.47349, 2.02625);
    glVertex2f(6, 1.96);
    glEnd();

    //1st_window
    glBegin(GL_QUADS);
    glColor3ub(221, 158, 61);
    glVertex2f(4.9122, 3.33915);
    glVertex2f(4.80321, 3.34045);
    glVertex2f(4.8, 2.6);
    glVertex2f(4.91004, 2.59156);
    glEnd();
    //2nd window
    glBegin(GL_QUADS);
    glColor3ub(221, 158, 61);
    glVertex2f(5.11792, 3.30495);
    glVertex2f(5.00295, 3.31322);
    glVertex2f(5.00035, 2.57379);
    glVertex2f(5.11233, 2.56);
    glEnd();
    //3rd window
    glBegin(GL_QUADS);
    glColor3ub(221, 158, 61);
    glVertex2f(5.7069, 3.23365);
    glVertex2f(5.60107, 3.25232);
    glVertex2f(5.59796, 2.5022);
    glVertex2f(5.71312, 2.49286);
    glEnd();
    //4rth window
    glBegin(GL_QUADS);
    glColor3ub(221, 158, 61);
    glVertex2f(5.91233, 3.20875);
    glVertex2f(5.8065, 3.23054);
    glVertex2f(5.8065, 2.4773);
    glVertex2f(5.91855, 2.46485);
    glEnd();

    //next row 
    //5th window
    glBegin(GL_QUADS);
    glColor3ub(221, 158, 61);
    glVertex2f(5.51, 2.44827);
    glVertex2f(5.39891, 2.46153);
    glVertex2f(5.39, 2.05);
    glVertex2f(5.51, 2.04);
    glEnd();
    //6th window
    glBegin(GL_QUADS);
    glColor3ub(221, 158, 61);
    glVertex2f(5.71417, 2.42627);
    glVertex2f(5.59802, 2.43456);
    glVertex2f(5.6, 2.02);
    glVertex2f(5.72, 2.00338);
    glEnd();


}

void bottomRightbuilding() {
    //roof
    glBegin(GL_QUADS);
    glColor3ub(48, 33, 30);
    glVertex2f(4.60729, 2.16452);
    glVertex2f(3.83891, 0.74136);
    glVertex2f(5.9955, 0.36659);
    glVertex2f(6, 1.96);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(73, 47, 49);
    glVertex2f(3.83891, 0.74136);
    glVertex2f(3.84895, 0.58293);
    glVertex2f(6, 0.2);
    glVertex2f(5.9955, 0.36659);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(67, 46, 48);
    glVertex2f(4.01, 0.56);
    glVertex2f(4, 0);
    glVertex2f(6, 0);
    glVertex2f(6, 0.2);
    glEnd();

}

void buildingWithVerticleWindows() {
    //Antenna top
    glBegin(GL_QUADS);
    glColor3ub(142, 99, 63); //
    glVertex2f(5.52085, 12.64831);//j1
    glVertex2f(5.51921, 12.1929);//k1
    glVertex2f(5.54875, 12.19425);//h1
    glVertex2f(5.54912, 12.64755);//i1
    glEnd();

    //Antenna mid
    glBegin(GL_QUADS);
    glColor3ub(113, 84, 63); // Building rgb(131, 91, 59)
    glVertex2f(5.51921, 12.1929);//k1
    glVertex2f(5.48451, 12.15581);//l1
    glVertex2f(5.58, 11.74);//f1
    glVertex2f(5.54875, 12.19425);//h1
    glEnd();

    //Antennabottom
    glBegin(GL_QUADS);
    glColor3ub(75, 49, 46); // Building rgb(131, 91, 59)
    glVertex2f(5.48451, 12.15581);//l1
    glVertex2f(5.487, 11.74127);//m1
    glVertex2f(5.58, 11.74);//f1
    glColor3ub(115, 82, 55);
    glVertex2f(5.57833, 12.15752);//g1
    glEnd();

    //Drawing Tall building right side main structure
    glBegin(GL_QUADS);
    glColor3ub(21, 22, 25); // Building rgb(21, 22, 25)
    glVertex2f(6, 11.4);
    glVertex2f(6, 5);
    glVertex2f(4.28, 5);
    glVertex2f(4.28, 11.36);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(67, 44, 41); // Building rgb(67, 44, 41)
    glVertex2f(5.92, 11.59);
    glVertex2f(5.92, 11.4);
    glVertex2f(5.69, 11.38);
    glVertex2f(5.7, 11.75);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(36, 28, 33); // Building rgb(36, 28, 33)
    glVertex2f(5.69, 11.38);
    glVertex2f(5.7, 11.75);
    glVertex2f(5.26, 11.73);
    glVertex2f(5.27, 11.38);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(36, 28, 33); // Building rgb(36, 28, 33)
    glVertex2f(5.27, 11.38);
    glVertex2f(5.27, 11.57);
    glVertex2f(4.95, 11.55);
    glVertex2f(4.94, 11.37);
    glEnd();

    for (float x = 4.34; x <= 6; x += 0.09) {
        glBegin(GL_QUADS);
        glColor3ub(188, 158, 115); // Building light lines rgb(188, 158, 115)
        glVertex2f(x, 11.24);
        glVertex2f(x + 0.06, 11.24);
        glColor3ub(88, 51, 46); // Building light lines rgb(88, 51, 46)S
        glVertex2f(x + 0.06, 5.32);
        glVertex2f(x, 5.32);
        glEnd();
    }
}

void wayneTower() {

    //antenna
    glBegin(GL_POLYGON);
    glColor3ub(134, 92, 70);
    glVertex2f(-5.15544, 13.50317);
    glColor3ub(51, 37, 37);
    glVertex2f(-5.19025, 13.50279);
    glColor3ub(84, 64, 54);
    glColor3ub(33, 31, 38);
    glVertex2f(-5.23, 12.79);

    glVertex2f(-5.13918, 12.78789);
    //glVertex2f(-5.1, 10.94);
    glEnd();
    //top tower
    glBegin(GL_POLYGON);
    glColor3ub(59, 43, 41); // Building rgb(59, 43, 41)
    glVertex2f(-3.53, 10.86);
    //glColor3ub(142, 89, 53); // Building rgb(142, 89, 53)
    glVertex2f(-3.53418, 12.38);
    glColor3ub(84, 64, 54); // Building rgb(84, 64, 54)
    glVertex2f(-4.4, 12.6);
    glColor3ub(52, 39, 41); // Building rgb(52, 39, 41)
    glVertex2f(-4.4, 10.92);
    //glVertex2f(-5.1, 10.94);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(35, 30, 36); // Building rgb(35, 30, 36)
    glVertex2f(-6, 10.86);
    glVertex2f(-4.4, 10.92);
    glVertex2f(-4.4, 12.6);
    glVertex2f(-5.2, 12.8);
    glVertex2f(-6, 12.51);
    glEnd();

    //Drawing  main structure
    glBegin(GL_QUADS);
    glColor3ub(31, 28, 33); // Building rgb(31, 28, 33)
    glVertex2f(-6.00025, 7.44631);
    glVertex2f(-4.09051, 7.36871);
    glVertex2f(-4.09986, 10.93592);
    glVertex2f(-6, 10.86204);
    glEnd();

    glBegin(GL_QUADS);

    glColor3ub(56, 40, 41); // Building rgb(56, 40, 41)
    glVertex2f(-4.09051, 7.36871);
    glVertex2f(-4.09986, 10.93592);
    glColor3ub(34, 28, 32); // Building rgb(56, 40, 41)
    glVertex2f(-3, 10.8);

    glVertex2f(-3, 7.37229);
    //glVertex2f(-6, 10.86);
    glEnd();

    //toptower
    glBegin(GL_TRIANGLES);
    glColor3ub(80, 51, 39);
    glVertex2f(-4.82, 12.71);
    glColor3ub(71, 46, 39);
    glVertex2f(-4.83099, 12.57187);
    glColor3ub(98, 64, 48);
    glVertex2f(-4.4, 12.6);
    glEnd();

    //windows
    // top tower
    //First floor
    glLineWidth(8);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-6, 12.2);
    glVertex2f(-6, 12.35512);
    glEnd();

    glLineWidth(0.6);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.82864, 12.19709);
    glVertex2f(-5.82696, 12.36184);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.65548, 12.20718);
    glVertex2f(-5.65548, 12.37697);
    glEnd();

    glLineWidth(0.3);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.57081, 12.20691);
    glVertex2f(-5.57187, 12.38837);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.27218, 12.23071);
    glVertex2f(-5.27386, 12.40219);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.16627, 12.23576);
    glVertex2f(-5.16795, 12.41228);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-4.9225, 12.25425);
    glVertex2f(-4.92418, 12.43077);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-4.9225, 12.25425);
    glVertex2f(-4.92418, 12.43077);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-4.77624, 12.25425);
    glVertex2f(-4.77792, 12.4459);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-4.67065, 12.26733);
    glVertex2f(-4.67032, 12.45263);
    glEnd();

    // other side
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-4.30796, 12.27174);
    glVertex2f(-4.30796, 12.46648);
    glEnd();

    glLineWidth(1.3);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-4.22316, 12.25917);
    glVertex2f(-4.22158, 12.44);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-4.07239, 12.22619);
    glVertex2f(-4.07239, 12.41308);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.9012, 12.17908);
    glVertex2f(-3.9012, 12.36911);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.80226, 12.15709);
    glVertex2f(-3.80069, 12.34241);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.68715, 12.14272);
    glVertex2f(-3.68553, 12.31153);
    glEnd();

    //Second floor
    glLineWidth(8);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-6, 11.93983);
    glVertex2f(-6, 12.1);
    glEnd();

    glLineWidth(0.6);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.66898, 11.95119);
    glVertex2f(-5.67222, 12.12487);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.51153, 11.96418);
    glVertex2f(-5.51316, 12.14434);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.35734, 11.97067);
    glVertex2f(-5.35896, 12.15246);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.02288, 11.99095);
    glVertex2f(-5.02288, 12.16607);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-4.52891, 12.02093);
    glVertex2f(-4.52891, 12.19138);
    glEnd();


    // // other side
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-4.26851, 12.00042);
    glVertex2f(-4.26851, 12.19138);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-4.12489, 11.98937);
    glVertex2f(-4.12332, 12.15666);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.95918, 11.94518);
    glVertex2f(-3.95761, 12.12352);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.83766, 11.92151);
    glVertex2f(-3.83609, 12.09353);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.73824, 11.90573);
    glVertex2f(-3.73824, 12.07617);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.60567, 11.87574);
    glVertex2f(-3.60251, 12.03987);
    glEnd();


    //Third floor
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.89957, 11.68573);
    glVertex2f(-5.89783, 11.86974);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.75548, 11.69441);
    glVertex2f(-5.75548, 11.87669);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.42043, 11.71177);
    glVertex2f(-5.42043, 11.89405);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.17218, 11.7326);
    glVertex2f(-5.17218, 11.90446);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-4.78158, 11.74822);
    glVertex2f(-4.78158, 11.9305);
    glEnd();

    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-4.59583, 11.76038);
    glVertex2f(-4.59756, 11.93918);
    glEnd();


    // // other side
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-4.3198, 11.76558);
    glVertex2f(-4.32327, 11.93398);
    glEnd();

    glLineWidth(2.6);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-4.11495, 11.71524);
    glVertex2f(-4.11322, 11.90446);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.95871, 11.69441);
    glVertex2f(-3.95871, 11.86627);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.79379, 11.65795);
    glVertex2f(-3.79205, 11.84023);
    glEnd();


    //Fourth floor
    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.91278, 11.4731);
    glVertex2f(-5.91278, 11.61402);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.83157, 11.48505);
    glVertex2f(-5.83157, 11.61402);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.37299, 11.50654);
    glVertex2f(-5.3706, 11.64507);
    glEnd();

    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.19146, 11.51132);
    glVertex2f(-5.18907, 11.64746);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-4.87858, 11.50893);
    glVertex2f(-4.87858, 11.6594);
    glEnd();

    glLineWidth(6.5);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-4.74932, 11.50893);
    glVertex2f(-4.74932, 11.6594);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-4.61932, 11.50549);
    glVertex2f(-4.61749, 11.6776);
    glEnd();


    // // other side
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-4.24086, 11.51132);
    glVertex2f(-4.24325, 11.66896);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-4.11666, 11.45638);
    glVertex2f(-4.11666, 11.64985);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.90409, 11.42533);
    glVertex2f(-3.90409, 11.59969);
    glEnd();

    glLineWidth(1.5);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.70107, 11.3919);
    glVertex2f(-3.70107, 11.56864);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.60131, 11.37732);
    glVertex2f(-3.60075, 11.54715);
    glEnd();

    //filth floor
    // other side
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-4.15633, 11.21206);
    glVertex2f(-4.1545, 11.37641);
    glEnd();

    glLineWidth(2.8);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.90798, 11.16824);
    glVertex2f(-3.90798, 11.35998);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.79659, 11.15728);
    glVertex2f(-3.79477, 11.34172);
    glEnd();

    //6th floor
// other side
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-4.1194, 10.94825);
    glVertex2f(-4.11947, 11.13577);
    glEnd();

    glLineWidth(1.6);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-4.05511, 10.94976);
    glVertex2f(-4.05511, 11.12129);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.95193, 10.94146);
    glVertex2f(-3.94974, 11.10762);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.8516, 10.93317);
    glVertex2f(-3.85, 11.1);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.64642, 10.91355);
    glVertex2f(-3.64728, 11.06418);
    glEnd();


    // Tower Logo
       //W
    glBegin(GL_POLYGON);
    glColor3ub(152, 94, 64);
    glVertex2f(-5.82666, 11.08687);
    glVertex2f(-5.75902, 11.28983);
    glVertex2f(-5.77953, 11.51969);
    glVertex2f(-5.8714, 11.51796);
    glVertex2f(-5.89019, 11.28498);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(152, 94, 64);
    glVertex2f(-5.82666, 11.08687);
    glVertex2f(-5.78938, 10.88175);
    glVertex2f(-5.65093, 10.88175);
    glVertex2f(-5.58534, 11.52303);
    glVertex2f(-5.72623, 11.51938);
    glVertex2f(-5.75902, 11.28983);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(152, 94, 64);
    glVertex2f(-5.82666, 11.08687);
    glVertex2f(-5.85983, 10.87446);
    glVertex2f(-5.99829, 10.87446);
    glVertex2f(-6, 11.5);
    glVertex2f(-5.92784, 11.49995);
    glVertex2f(-5.89019, 11.28498);
    glEnd();
    //A
    glBegin(GL_POLYGON);
    glColor3ub(152, 94, 64);
    glVertex2f(-5.60356, 10.88539);
    glVertex2f(-5.4651, 10.8866);
    glVertex2f(-5.45538, 11.02506);
    glVertex2f(-5.38251, 11.02628);
    glVertex2f(-5.36915, 10.8866);
    glVertex2f(-5.22583, 10.89632);
    glVertex2f(-5.33636, 11.52546);
    glVertex2f(-5.50154, 11.52546);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(35, 30, 36);
    glVertex2f(-5.4651, 10.8866);
    glVertex2f(-5.36915, 10.89511);
    glVertex2f(-5.38251, 11.02628);
    glVertex2f(-5.45538, 11.02628);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(35, 30, 36);
    glVertex2f(-5.41655, 11.26);
    glVertex2f(-5.46, 11.11);
    glVertex2f(-5.37, 11.11);
    glEnd();

    //Y
    glBegin(GL_POLYGON);
    glColor3ub(152, 94, 64);
    glVertex2f(-5.09764, 11.3497);
    glVertex2f(-5.1, 10.9);
    glVertex2f(-5.1817, 10.89838);
    glVertex2f(-5.18318, 11.14617);
    glVertex2f(-5.29675, 11.53554);
    glVertex2f(-5.13598, 11.53111);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(152, 94, 64);
    glVertex2f(-5.09764, 11.3497);
    glVertex2f(-5.1, 10.9);
    glVertex2f(-5, 10.9);
    glVertex2f(-5.00177, 11.17419);
    glVertex2f(-4.89557, 11.54439);
    glVertex2f(-5.05191, 11.54291);
    glEnd();

    //N
    glBegin(GL_POLYGON);
    glColor3ub(152, 94, 64);
    glVertex2f(-4.73653, 11.07);
    glVertex2f(-4.68409, 11.35);
    glVertex2f(-4.72779, 11.55061);
    glVertex2f(-4.87782, 11.55353);
    glVertex2f(-4.87782, 10.91115);
    glVertex2f(-4.74673, 10.91407);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(152, 94, 64);
    glVertex2f(-4.68409, 11.35);
    glVertex2f(-4.73653, 11.07);
    glVertex2f(-4.69574, 10.91844);
    glVertex2f(-4.52823, 10.92135);
    glVertex2f(-4.5326, 11.55207);
    glVertex2f(-4.66807, 11.54916);
    glEnd();

    //E
    glBegin(GL_POLYGON);
    glColor3ub(152, 94, 64);
    glVertex2f(-4.49659, 10.93531);
    glVertex2f(-4.19376, 10.93531);
    glVertex2f(-4.19479, 11.08621);
    glVertex2f(-4.49761, 11.08621);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(152, 94, 64);
    glVertex2f(-4.49537, 11.391);
    glVertex2f(-4.19115, 11.39193);
    glVertex2f(-4.19301, 11.56925);
    glVertex2f(-4.49648, 11.56803);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(152, 94, 64);
    glVertex2f(-4.34979, 11.32437);
    glVertex2f(-4.35, 11.39);
    glVertex2f(-4.49537, 11.391);
    glVertex2f(-4.49761, 11.08518);
    glVertex2f(-4.36, 11.09);
    glVertex2f(-4.35595, 11.15601);
    glVertex2f(-4.26972, 11.32539);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(152, 94, 64);
    glVertex2f(-4.5, 11.32);
    glVertex2f(-4.5, 11.15);
    glVertex2f(-4.2687, 11.15601);
    glVertex2f(-4.26972, 11.32539);
    glEnd();

    //E shadow
    glBegin(GL_POLYGON);
    glColor3ub(12, 24, 38);
    glVertex2f(-4.19115, 11.39193);
    glVertex2f(-4.13284, 11.38239);
    glVertex2f(-4.13207, 11.53779);
    glVertex2f(-4.19301, 11.56925);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(12, 24, 38);
    glVertex2f(-4.19376, 10.93531);
    glVertex2f(-4.13592, 10.93388);
    glVertex2f(-4.13515, 11.06543);
    glVertex2f(-4.19479, 11.08621);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(12, 24, 38);
    glVertex2f(-4.2687, 11.15601);
    glVertex2f(-4.21285, 11.1516);
    glVertex2f(-4.21131, 11.30853);
    glVertex2f(-4.26972, 11.32539);
    glEnd();

    //Bottom tower windows
    //1
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.98092, 10.45406);
    glVertex2f(-5.98092, 10.66696);
    glEnd();

    glLineWidth(4.5);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.67472, 10.44968);
    glVertex2f(-5.67472, 10.67145);
    glEnd();

    glLineWidth(4.5);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.41659, 10.45695);
    glVertex2f(-5.41659, 10.67872);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-4.45317, 10.48967);
    glVertex2f(-4.45681, 10.7078);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.13856, 10.47257);
    glVertex2f(-5.13856, 10.68547);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-4.78989, 10.488);
    glVertex2f(-4.78989, 10.7009);
    glEnd();

    // // other side
    glLineWidth(1.9);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.99072, 10.45714);
    glVertex2f(-3.99072, 10.69165);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.84262, 10.4664);
    glVertex2f(-3.84262, 10.67313);
    glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.56492, 10.4232);
    glVertex2f(-3.56492, 10.64228);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.3335, 10.41703);
    glVertex2f(-3.3335, 10.62685);
    glEnd();

    glLineWidth(3.5);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.11238, 10.39604);
    glVertex2f(-3.11238, 10.60168);
    glEnd();


    //2
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.98092, 10.45406 - 0.1091200000);
    glVertex2f(-5.98092, 10.66696 - 0.54237);
    glEnd();

    // glLineWidth(4.5);
    // glBegin(GL_LINES);
    // glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    // glVertex2f(-5.67472, 10.44968 - 0.1091200000);
    // glVertex2f(-5.67472, 10.67145 - 0.54237);
    // glEnd();

    glLineWidth(4.5);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.41659, 10.45695 - 0.1091200000);
    glVertex2f(-5.41659, 10.67872 - 0.54237);
    glEnd();

    // glLineWidth(3);
    // glBegin(GL_LINES);
    // glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    // glVertex2f(-4.45317, 10.48967 - 0.1091200000);
    // glVertex2f(-4.45681, 10.7078 - 0.54237);
    // glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.13856, 10.47257 - 0.1091200000);
    glVertex2f(-5.13856, 10.68547 - 0.54237);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-4.78989, 10.488 - 0.1091200000);
    glVertex2f(-4.78989, 10.7009 - 0.54237);
    glEnd();

    // // other side
    glLineWidth(1.9);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.99072, 10.45714 - 0.0899600000);
    glVertex2f(-3.99072, 10.69165 - 0.54814);
    glEnd();

    // glLineWidth(3);
    // glBegin(GL_LINES);
    // glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    // glVertex2f(-3.84262, 10.4664 - 0.0899600000);
    // glVertex2f(-3.84262, 10.67313 - 0.54814);
    // glEnd();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.56492, 10.4232 - 0.0899600000);
    glVertex2f(-3.56492, 10.64228 - 0.54814);
    glEnd();

    // glLineWidth(4);
    // glBegin(GL_LINES);
    // glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    // glVertex2f(-3.3335, 10.41703 - 0.0899600000);
    // glVertex2f(-3.3335, 10.62685 - 0.54814);
    // glEnd();

    glLineWidth(3.5);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.11238, 10.39604 - 0.0828500000);
    glVertex2f(-3.11238, 10.60168 - 0.54814);
    glEnd();


    //3
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.90908, 9.8218);
    glVertex2f(-5.90639, 10.03484);
    glEnd();

    glLineWidth(8);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.51537, 9.8272);
    glVertex2f(-5.51807, 10.04293);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.15942, 9.83259);
    glVertex2f(-5.15942, 10.04293);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-4.45317, 10.48967);
    glVertex2f(-4.45681, 10.7078);
    glEnd();

    glLineWidth(2.6);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-4.74414, 9.82989);
    glVertex2f(-4.74414, 10.04293);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-4.56616, 9.84068);
    glVertex2f(-4.56347, 10.04832);
    glEnd();

    glLineWidth(2.8);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-4.35313, 9.83798);
    glVertex2f(-4.35583, 10.05641);
    glEnd();

    // // other side
    glLineWidth(1.9);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.99072, 9.82102);
    glVertex2f(-3.98908, 10.03753);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.76737, 9.8151);
    glVertex2f(-3.76737, 10.0207);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.52918, 9.82302);
    glVertex2f(-3.52918, 10.01124);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.2, 9.8);
    glVertex2f(-3.2, 10);
    glEnd();

    glLineWidth(3.5);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.0688, 9.81793);
    glVertex2f(-3.0688, 9.99853);
    glEnd();


    //4
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.90908, 9.8218 - 0.0879000000);
    glVertex2f(-5.90639, 10.03484 - 0.5219900000);
    glEnd();

    // glLineWidth(8);
    // glBegin(GL_LINES);
    // glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    // glVertex2f(-5.51537, 9.8272 - 0.0879000000);
    // glVertex2f(-5.51807, 10.04293 - 0.5219900000);
    // glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.15942, 9.83259 - 0.0879000000);
    glVertex2f(-5.15942, 10.04293 - 0.5219900000);
    glEnd();

    // glLineWidth(3);
    // glBegin(GL_LINES);
    // glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    // glVertex2f(-4.45317, 10.48967 - 0.0879000000);
    // glVertex2f(-4.45681, 10.7078 - 0.5219900000);
    // glEnd();

    glLineWidth(2.6);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-4.74414, 9.82989 - 0.0879000000);
    glVertex2f(-4.74414, 10.04293 - 0.5219900000);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-4.56616, 9.84068 - 0.0879000000);
    glVertex2f(-4.56347, 10.04832 - 0.5219900000);
    glEnd();

    // glLineWidth(2.8);
    // glBegin(GL_LINES);
    // glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    // glVertex2f(-4.35313, 9.83798 - 0.0879000000);
    // glVertex2f(-4.35583, 10.05641 - 0.5219900000);
    // glEnd();

    // // other side
    glLineWidth(1.9);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.99072, 9.82102 - 0.12102);
    glVertex2f(-3.98908, 10.03753 - 0.53753);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.76737, 9.8151 - 0.12102);
    glVertex2f(-3.76737, 10.0207 - 0.53753);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.52918, 9.82302 - 0.12102);
    glVertex2f(-3.52918, 10.01124 - 0.53753);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.2, 9.8 - 0.12102);
    glVertex2f(-3.2, 10 - 0.53753);
    glEnd();

    glLineWidth(3.5);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.0688, 9.81793 - 0.12102);
    glVertex2f(-3.0688, 9.99853 - 0.53753);
    glEnd();

    //4
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.90908, 9.8218 - 0.0879000000);
    glVertex2f(-5.90639, 10.03484 - 0.5219900000);
    glEnd();

    glLineWidth(8);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.51537, 9.8272 - 0.0879000000);
    glVertex2f(-5.51807, 10.04293 - 0.5219900000);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.15942, 9.83259 - 0.0879000000);
    glVertex2f(-5.15942, 10.04293 - 0.5219900000);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-4.45317, 10.48967 - 0.0879000000);
    glVertex2f(-4.45681, 10.7078 - 0.5219900000);
    glEnd();

    glLineWidth(2.6);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-4.74414, 9.82989 - 0.0879000000);
    glVertex2f(-4.74414, 10.04293 - 0.5219900000);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-4.56616, 9.84068 - 0.0879000000);
    glVertex2f(-4.56347, 10.04832 - 0.5219900000);
    glEnd();

    glLineWidth(2.8);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-4.35313, 9.83798 - 0.0879000000);
    glVertex2f(-4.35583, 10.05641 - 0.5219900000);
    glEnd();

    // // other side
    glLineWidth(1.9);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.99072, 9.82102 - 0.12102);
    glVertex2f(-3.98908, 10.03753 - 0.53753);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.76737, 9.8151 - 0.12102);
    glVertex2f(-3.76737, 10.0207 - 0.53753);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.52918, 9.82302 - 0.12102);
    glVertex2f(-3.52918, 10.01124 - 0.53753);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.2, 9.8 - 0.12102);
    glVertex2f(-3.2, 10 - 0.53753);
    glEnd();

    glLineWidth(3.5);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.0688, 9.81793 - 0.12102);
    glVertex2f(-3.0688, 9.99853 - 0.53753);
    glEnd();

    //5
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.85116, 8.87818);
    glVertex2f(-5.85116, 9.40239);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.54006, 8.86348);
    glVertex2f(-5.53761, 9.40729);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.34165, 8.86838);
    glVertex2f(-5.33675, 9.39994);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.033, 8.86348);
    glVertex2f(-5.033, 9.40729);
    glEnd();

    glLineWidth(8);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-4.75864, 8.85123);
    glVertex2f(-4.75619, 9.40239);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-4.32017, 8.86348);
    glVertex2f(-4.31282, 9.40484);
    glEnd();


    // // other side
    glLineWidth(2.4);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-4.00295, 8.83609);
    glVertex2f(-4, 9.4);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.79981, 8.84668);
    glVertex2f(-3.8, 9.4);
    glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.66697, 8.86091);
    glVertex2f(-3.66697, 9.38281);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.43863, 8.90885);
    glVertex2f(-3.44185, 9.37627);
    glEnd();


    //6
    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.85116, 8.87818 - 0.0993200000);
    glVertex2f(-5.85116, 8.38606 - 1.01633);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.54006, 8.86348 - 0.0993200000);
    glVertex2f(-5.53761, 9.40729 - 1.01633);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.34165, 8.86838 - 0.0993200000);
    glVertex2f(-5.33675, 9.39994 - 1.01633);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-5.033, 8.86348 - 0.0993200000);
    glVertex2f(-5.033, 9.40729 - 1.01633);
    glEnd();

    // glLineWidth(8);
    // glBegin(GL_LINES);
    // glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    // glVertex2f(-4.75864, 8.85123 - 0.0993200000);
    // glVertex2f(-4.75619, 9.40239 - 1.01633);
    // glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(225, 167, 118); // Building rgb(225, 167, 118)
    glVertex2f(-4.32017, 8.86348 - 0.0993200000);
    glVertex2f(-4.31282, 9.40484 - 1.01633);
    glEnd();


    // // other side
    glLineWidth(2.4);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-4.00295, 8.83609 - 0.1059200000);
    glVertex2f(-4, 9.4 - 1.14704);
    glEnd();

    // glLineWidth(3);
    // glBegin(GL_LINES);
    // glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    // glVertex2f(-3.79981, 8.84668 - 0.1059200000);
    // glVertex2f(-3.8, 9.4 - 1.14704 - 1.01633);
    // glEnd();

    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.66697, 8.86091 - 0.1059200000);
    glVertex2f(-3.66697, 9.38281 - 1.01633);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.43863, 8.90885 - 0.1059200000);
    glVertex2f(-3.44185, 9.37627 - 1.01633);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.20366, 8.92095);
    glVertex2f(-3.20366, 9.7342);
    glEnd();


    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.67289, 8.48554);
    glVertex2f(-3.67289, 8.75533);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glColor3ub(180, 125, 71); // Building rgb(180, 125, 71)
    glVertex2f(-3.1326, 7.65514);
    glVertex2f(-3.12956, 8.89564);
    glEnd();

}

void batmanBuilding() {

    glBegin(GL_POLYGON);
    glColor3ub(80, 43, 34);
    glVertex2f(-0.97917, 5.33827);
    glVertex2f(-5.99, 3.13);
    glColor3ub(33, 19, 14);
    glVertex2f(-5.9889, 2.82377);
    glVertex2f(-0.95053, 5.10231);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(23, 20, 24);
    glVertex2f(-0.74582, 6.34003);
    glVertex2f(-5.99, 4.71);
    glColor3ub(64, 37, 33);
    glVertex2f(-5.99, 3.13);
    glVertex2f(-1.1, 5.2);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(22, 19, 20);
    glVertex2f(-0.74884, 7.18447);
    glVertex2f(-6, 6);
    glColor3ub(20, 16, 16);
    glVertex2f(-5.99, 4.71);
    glVertex2f(-0.74582, 6.34003);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(33, 19, 16);
    glVertex2f(-5.99227, 7.2242);
    glVertex2f(-6.01016, 6.63301);
    glColor3ub(36, 24, 21);
    glVertex2f(-2.89229, 7.2105);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(35, 22, 21);
    glVertex2f(-0.74884, 7.18447);
    glVertex2f(-2.89229, 7.2105);
    glColor3ub(32, 20, 14);
    glVertex2f(-6.01016, 6.63301);
    glVertex2f(-6., 6);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(32, 19, 14);
    glVertex2f(-0.77763, 7.6);
    glVertex2f(-5.98641, 7.71089);
    // glColor3ub(32, 20, 14);
    glVertex2f(-5.99227, 7.2242);
    glVertex2f(-0.74884, 7.18447);
    glEnd();

    //building body
    glBegin(GL_POLYGON);
    glColor3ub(18, 14, 16); // Building rgb(18, 14, 16)
    glVertex2f(-6, 2.8196);
    glVertex2f(-6, 0);
    glVertex2f(-3.33, 0);
    glColor3ub(32, 24, 25); // Building rgb(32, 24, 25)
    glVertex2f(-1.32857, 1.61253);
    glVertex2f(-1.32902, 4.95088);
    glEnd();

    //building mid ledge
    glBegin(GL_POLYGON);
    glColor3ub(13, 20, 26); // Building rgb(18, 14, 16)
    glVertex2f(-3.72, 0);
    glVertex2f(-3.53812, 0.00917);
    glColor3ub(13, 20, 26); // Building rgb(32, 24, 25)
    glVertex2f(-0.89972, 2.18233);
    glVertex2f(-0.87452, 2.33164);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(18, 14, 16); // Building rgb(18, 14, 16)
    glVertex2f(-4.08156, 0.00368);
    glVertex2f(-3.72, 0);
    glColor3ub(32, 24, 25); // Building rgb(32, 24, 25)
    glVertex2f(-0.87452, 2.33164);
    glVertex2f(-1.31265, 2.39414);
    glEnd();

    //bottom ledge
    glBegin(GL_QUADS);
    glColor3ub(21, 16, 16); // Building rgb(21, 16, 16)
    glVertex2f(-2.2, 0);
    glVertex2f(-1.51, 0);
    glColor3ub(33, 22, 23); // Building rgb(33, 22, 23)
    glVertex2f(-0.57942, 0.87968);
    glVertex2f(-0.6014, 1.50076);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(4, 11, 19); // Building rgb(4, 11, 19)
    glVertex2f(-3.33, 0);
    glVertex2f(-2.2, 0);
    glColor3ub(9, 15, 18); // Building rgb(9, 15, 18)
    glVertex2f(-0.6014, 1.50076);
    glVertex2f(-1.32857, 1.61253);
    glEnd();

    //window 1
    glBegin(GL_QUADS);
    glColor3ub(115, 61, 42);
    glVertex2f(-3.63037, 3.52919);
    glVertex2f(-4.26819, 3.24707);
    glColor3ub(0, 33, 30);//not wrorking
    glVertex2f(-4.25812, 0.04495);
    glVertex2f(-3.66402, 0.49808);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(10, 7, 7);
    glVertex2f(-3.91, 3.41);
    glVertex2f(-3.92, 0.31);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(10, 7, 7);
    glVertex2f(-3.64, 2.82);
    glVertex2f(-4.27, 2.48);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(10, 7, 7);
    glVertex2f(-3.65, 1.99);
    glVertex2f(-4.26, 1.61);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(10, 7, 7);
    glVertex2f(-3.66, 1.23);
    glVertex2f(-4.26, 0.84);
    glEnd();

    //window 2
    glBegin(GL_QUADS);
    glColor3ub(191, 126, 69);
    glVertex2f(-1.68159, 4.49618);
    glVertex2f(-2.20918, 4.26266);
    glVertex2f(-2.20053, 1.62472);
    glVertex2f(-1.69889, 1.98798);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(10, 7, 7);
    glVertex2f(-1.93, 4.39);
    glVertex2f(-1.91, 1.83);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(10, 7, 7);
    glVertex2f(-1.65, 3.89);
    glVertex2f(-2.21, 3.61);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(10, 7, 7);
    glVertex2f(-1.69, 3.22);
    glVertex2f(-2.2, 2.88);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(10, 7, 7);
    glVertex2f(-1.69, 2.61);
    glVertex2f(-2.2, 2.28);
    glEnd();

}

void buildingNextTobuildingWithVerticleWindows() {
    glBegin(GL_QUADS);
    glColor3ub(21, 20, 23); // Building rgb(21, 20, 23)
    glVertex2f(3.8, 8.7);
    glVertex2f(4.28, 8.69);
    glVertex2f(4.28, 9.73);
    glVertex2f(3.8, 9.73);
    glEnd();


    //Windows

    //First floor
    for (float i = 3.83051; i <= 4.2; i += 0.0818000000)
    {
        glLineWidth(2.5);
        glBegin(GL_LINES);
        glColor3ub(206, 158, 114); // Building rgb(206, 158, 114)
        glVertex2f(i, 9.69971);
        glVertex2f(i, 9.63574);
        glEnd();
    }
    //Second floor
    for (float i = 3.854; i <= 4.25015; i += 0.0653600000)
    {
        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3ub(206, 158, 114); // Building rgb(206, 158, 114)
        glVertex2f(i, 9.53336);
        glVertex2f(i, 9.60219);
        glEnd();
    }

    //Third floor
    for (float i = 3.82818; i <= 4.25015; i += 0.08311)
    {
        glLineWidth(2.2);
        glBegin(GL_LINES);
        glColor3ub(206, 158, 114); // Building rgb(206, 158, 114)
        glVertex2f(i, 9.42444);
        glVertex2f(i, 9.49947);
        glEnd();
    }

    //Forth floor
    for (float i = 3.89999; i <= 4.25015; i += 0.08311)
    {
        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3ub(207, 146, 94); // Building rgb(207, 146, 94)
        glVertex2f(i, 9.32762);
        glVertex2f(i, 9.4);
        glEnd();
    }

    //Fifth floor
    for (float i = 3.85562; i <= 4.25015; i += 0.08311)
    {
        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3ub(175, 126, 91); // Building rgb(175, 126, 91)
        glVertex2f(i, 9.22354);
        glVertex2f(i, 9.28486);
        glEnd();
    }
    //Sixth floor
    for (float i = 3.84072; i <= 4.3; i += 0.0818000000)
    {
        glLineWidth(2.5);
        glBegin(GL_LINES);
        glColor3ub(191, 147, 102); // Building rgb(191, 147, 102)
        glVertex2f(i, 9.12077);
        glVertex2f(i, 9.1843);
        glEnd();
    }

    //Seventh floor
    for (float i = 3.85164; i <= 4.25015; i += 0.084)
    {
        glLineWidth(2.2);
        glBegin(GL_LINES);
        glColor3ub(175, 161, 97); // Building rgb(175, 161, 97)
        glVertex2f(i, 9.02349);
        glVertex2f(i, 9.08503);
        glEnd();
    }

    //8th floor
    for (float i = 3.86231; i <= 4.25015; i += 0.08311)
    {
        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3ub(174, 160, 82); // Building rgb(174, 160, 82)
        glVertex2f(i, 8.91063);
        glVertex2f(i, 8.97637);
        glEnd();
    }


    //9th floor
    for (float i = 3.84753; i <= 4.25015; i += 0.08311)
    {
        glLineWidth(2);
        glBegin(GL_LINES);
        glColor3ub(135, 120, 49); // Building rgb(135, 120, 49)
        glVertex2f(i, 8.81608);
        glVertex2f(i, 8.87739);
        glEnd();
    }

    //10th floor
    for (float i = 3.85049; i <= 4.25015; i += 0.084)
    {
        glLineWidth(2.2);
        glBegin(GL_LINES);
        glColor3ub(104, 94, 64); // Building rgb(104, 94, 64)
        glVertex2f(i, 8.7);
        glVertex2f(i, 8.7725);
        glEnd();
    }

}

void policeBuilding() {
    //roof
    glBegin(GL_QUADS);
    glColor3ub(124, 63, 44);
    glVertex2f(4.47239, 2.20322);
    glVertex2f(3.76, 2.32);
    glColor3ub(48, 33, 34);
    glVertex2f(3.76, 1.06);
    glVertex2f(3.826, 1.04718);
    glEnd();
    //roofboxroof
    glBegin(GL_QUADS);
    glColor3ub(136, 79, 55);
    glVertex2f(4.24392, 3.01404);
    glVertex2f(3.56628, 3.0946);
    glVertex2f(3.76, 2.71);
    glVertex2f(4.01694, 2.68053);
    glEnd();
    //roofbox
    glBegin(GL_QUADS);
    glColor3ub(19, 28, 38);
    glVertex2f(3.76, 2.71);
    glVertex2f(3.76, 1.88);
    glVertex2f(4.02621, 1.85602);
    glVertex2f(4.01694, 2.68053);
    glEnd();
    //roofboxside
    glBegin(GL_QUADS);
    glColor3ub(64, 40, 36);
    glVertex2f(4.23422, 3.00754);
    glVertex2f(4.01639, 2.68);
    glColor3ub(51, 34, 35);
    glVertex2f(4.0245, 1.845);
    glVertex2f(4.26099, 2.2379);
    glEnd();

    //roofbox2roof
    glBegin(GL_QUADS);
    glColor3ub(66, 37, 27);
    glVertex2f(2.78904, 3.89236);
    glVertex2f(2.38865, 3.93822);
    glColor3ub(171, 95, 43);
    glVertex2f(2.15984, 3.73458);
    glVertex2f(2.59458, 3.70026);
    glEnd();
    //roofbox2front
    glBegin(GL_QUADS);
    glColor3ub(140, 56, 37);
    glVertex2f(2.59458, 3.70026);
    glVertex2f(2.15984, 3.73458);
    glColor3ub(137, 52, 32);
    glVertex2f(2.16343, 3.21424);
    glVertex2f(2.58951, 3.15239);
    glEnd();
    //roofbox2side
    glBegin(GL_QUADS);
    glColor3ub(140, 56, 37);
    glVertex2f(2.59458, 3.70026);
    glVertex2f(2.15984, 3.73458);
    glColor3ub(137, 52, 32);
    glVertex2f(2.16343, 3.21424);
    glVertex2f(2.58951, 3.15239);
    glEnd();
    //billboard
    glBegin(GL_QUADS);
    glColor3ub(29, 27, 32);
    glVertex2f(3.75885, 3.03858);
    glVertex2f(0.57507, 3.4297);
    glVertex2f(0.55727, 1.56055);
    glVertex2f(3.76, 1.06);
    glEnd();
    //sidewall
    glBegin(GL_QUADS);
    glColor3ub(40, 25, 22);
    glVertex2f(2.78904, 3.89236);
    glVertex2f(2.59458, 3.70026);
    glColor3ub(80, 35, 29);
    glVertex2f(2.58951, 3.15239);
    glVertex2f(2.79822, 3.15112);
    glEnd();


    //ledge
    glBegin(GL_QUADS);
    glColor3ub(73, 45, 44);
    glVertex2f(0.50014, 1.58612);
    glVertex2f(0.41848, 1.52634);
    glVertex2f(3.7814, 0.96076);
    glVertex2f(3.826, 1.05);
    glEnd();

    //front below
    glBegin(GL_QUADS);
    glColor3ub(38, 35, 38);
    glVertex2f(0.7, 1.29);
    glVertex2f(0.70938, -0.00055);
    glVertex2f(3.77315, 0.00238);
    glVertex2f(3.76303, 0.78);
    glEnd();
    //1st window
    glBegin(GL_QUADS);
    glColor3ub(235, 201, 136);
    glVertex2f(1.02909, 0.83457);
    glVertex2f(0.83844, 0.85121);
    glVertex2f(0.83833, 0.35357);
    glVertex2f(1.02542, 0.33415);
    glEnd();
    //line
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(66, 48, 46);
    glVertex2f(0.84, 0.61);
    glVertex2f(1.03, 0.58);
    glEnd();
    //2nd window
    glBegin(GL_QUADS);
    glColor3ub(235, 201, 136);
    glVertex2f(1.36419, 0.77159);
    glVertex2f(1.17216, 0.79384);
    glVertex2f(1.1663, 0.2997);
    glVertex2f(1.36068, 0.26809);
    glEnd();
    //line
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(66, 48, 46);
    glVertex2f(1.17, 0.55);
    glVertex2f(1.36, 0.52);
    glEnd();
    //3rd window
    glBegin(GL_QUADS);
    glColor3ub(235, 201, 136);
    glVertex2f(2.03434, 0.64471);
    glVertex2f(1.86108, 0.67719);
    glVertex2f(1.85747, 0.17907);
    glVertex2f(2.03073, 0.15741);
    glEnd();
    //line
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(66, 48, 46);
    glVertex2f(1.86, 0.43);
    glVertex2f(2.03, 0.4);
    glEnd();

    //4th window
    glBegin(GL_QUADS);
    glColor3ub(235, 201, 136);
    glVertex2f(2.74097, 0.52306);
    glVertex2f(2.55001, 0.55084);
    glVertex2f(2.54306, 0.05433);
    glVertex2f(2.74097, 0.02309);
    glEnd();
    //line
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(66, 48, 46);
    glVertex2f(2.55, 0.3);
    glVertex2f(2.74, 0.28);
    glEnd();

    //4th window
    glBegin(GL_QUADS);
    glColor3ub(235, 201, 136);
    glVertex2f(3.09512, 0.46056);
    glVertex2f(2.9111, 0.49528);
    glVertex2f(2.9, 0);
    glVertex2f(3.1, 0);
    glEnd();
    //line
    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(66, 48, 46);
    glVertex2f(2.91, 0.24);
    glVertex2f(3.09, 0.2071);
    glEnd();
    //side
    glBegin(GL_QUADS);
    glColor3ub(28, 26, 30);
    glVertex2f(4.47349, 2.02625);
    glVertex2f(3.755, 1);
    glVertex2f(3.77364, 0);
    glVertex2f(4.48, 0);
    glEnd();

    //ledge
    glBegin(GL_QUADS);
    glColor3ub(43, 37, 41);
    glVertex2f(0.41848, 1.52634);
    glVertex2f(0.39982, 1.33326);
    glVertex2f(3.78498, 0.77462);
    glVertex2f(3.7814, 0.96076);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(38, 30, 32);
    glVertex2f(3.7814, 0.98);
    glVertex2f(3.78498, 0.77462);
    glVertex2f(4.48108, 2.02938);
    glVertex2f(4.47239, 2.20322);
    glEnd();


}

void buildingfrontofgcpd() {
    glBegin(GL_QUADS);
    glColor3ub(124, 63, 44);
    glVertex2f(4.84025, 6.22573);
    glVertex2f(2.63021, 6.19469);
    glVertex2f(2.14548, 5.99765);
    glVertex2f(4.38408, 5.87093);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(25, 24, 28);
    glVertex2f(4.38408, 5.87093);
    glVertex2f(2.14548, 5.99765);
    glVertex2f(2, 3);
    glVertex2f(4.60729, 2.16452);
    glEnd();
    circle(0.49, 3.04092, 5.87093, 24, 24, 29);
    circle(0.36, 3.04092, 5.87093, 107, 63, 48);
    circle(0.26, 3.04092, 5.87093, 0, 0, 0);
    circle(0.24, 3.04092, 5.87093, 107, 63, 48);

    //w1
    glBegin(GL_QUADS);
    glColor3ub(236, 193, 107);
    glVertex2f(2.38951, 5.88523);
    glVertex2f(2.26945, 5.89567);
    glVertex2f(2.27467, 5.59292);
    glVertex2f(2.39995, 5.57726);
    glEnd();
    //w2
    glBegin(GL_QUADS);
    glColor3ub(236, 193, 107);
    glVertex2f(3.81334, 5.79891);
    glVertex2f(3.68377, 5.80765);
    glVertex2f(3.68377, 5.48589);
    glVertex2f(3.8148, 5.47716);
    glEnd();
    //w3
    glBegin(GL_QUADS);
    glColor3ub(236, 193, 107);
    glVertex2f(3.14416, 5.42213);
    glVertex2f(2.96831, 5.43742);
    glVertex2f(2.97213, 5.10101);
    glVertex2f(3.14034, 5.08954);
    glEnd();
    //w4
    glBegin(GL_QUADS);
    glColor3ub(236, 193, 107);
    glVertex2f(3.43088, 5.41066);
    glVertex2f(3.26649, 5.41449);
    glVertex2f(3.26649, 5.07043);
    glVertex2f(3.44234, 5.05896);
    glEnd();

    //w5
    glBegin(GL_QUADS);
    glColor3ub(236, 193, 107);
    glVertex2f(4.02725, 5.36479);
    glVertex2f(3.90491, 5.38008);
    glVertex2f(3.89727, 5.05131);
    glVertex2f(4.02342, 5.04749);
    glEnd();

    //w6
    glBegin(GL_QUADS);
    glColor3ub(236, 193, 107);
    glVertex2f(2.38837, 5.06771);
    glVertex2f(2.27215, 5.08356);
    glVertex2f(2.26687, 4.76661);
    glVertex2f(2.39893, 4.75076);
    glEnd();

    //w7
    glBegin(GL_QUADS);
    glColor3ub(236, 193, 107);
    glVertex2f(2.85091, 5.00411);
    glVertex2f(2.68441, 5.00694);
    glVertex2f(2.68158, 4.66545);
    glVertex2f(2.84809, 4.65981);
    glEnd();

    //w8
    glBegin(GL_QUADS);
    glColor3ub(236, 193, 107);
    glVertex2f(3.44096, 4.94894);
    glVertex2f(3.26974, 4.95258);
    glVertex2f(3.2661, 4.61743);
    glVertex2f(3.43732, 4.59921);
    glEnd();

    //w9
    glBegin(GL_QUADS);
    glColor3ub(236, 193, 107);
    glVertex2f(4.03074, 4.95136);
    glVertex2f(3.89531, 4.96427);
    glVertex2f(3.90559, 4.64);
    glVertex2f(4.0399, 4.63695);
    glEnd();

    //w10
    glBegin(GL_QUADS);
    glColor3ub(236, 193, 107);
    glVertex2f(4.24443, 4.92084);
    glVertex2f(4.11622, 4.94221);
    glVertex2f(4.11011, 4.61863);
    glVertex2f(4.25969, 4.60947);
    glEnd();

    //w11
    glBegin(GL_QUADS);
    glColor3ub(236, 193, 107);
    glVertex2f(2.68761, 4.37137);
    glVertex2f(2.48919, 4.37748);
    glVertex2f(2.48919, 4.04475);
    glVertex2f(2.68761, 4.02643);
    glEnd();

    //w12
    glBegin(GL_QUADS);
    glColor3ub(236, 193, 107);
    glVertex2f(3.29202, 4.30727);
    glVertex2f(3.10886, 4.31643);
    glVertex2f(3.10581, 3.98675);
    glVertex2f(3.29202, 3.96538);
    glEnd();

    //w13
    glBegin(GL_QUADS);
    glColor3ub(236, 193, 107);
    glVertex2f(3.79875, 4.2859);
    glVertex2f(3.66749, 4.29201);
    glVertex2f(3.67054, 3.95622);
    glVertex2f(3.81401, 3.94096);
    glEnd();

    //w14
    glBegin(GL_QUADS);
    glColor3ub(236, 193, 107);
    glVertex2f(4.28716, 4.2279);
    glVertex2f(4.1498, 4.24316);
    glVertex2f(4.15285, 3.90127);
    glVertex2f(4.29327, 3.88906);
    glEnd();

    //w15
    glBegin(GL_QUADS);
    glColor3ub(236, 193, 107);
    glVertex2f(4.04906, 3.8097);
    glVertex2f(3.89948, 3.81885);
    glVertex2f(3.90004, 3.47749);
    glVertex2f(4.04906, 3.47086);
    glEnd();

    //sidewall
    glBegin(GL_QUADS);
    glColor3ub(38, 37, 32);
    glVertex2f(4.84025, 6.22573);
    glVertex2f(4.38408, 5.87093);
    glVertex2f(4.60729, 2.16452);
    glVertex2f(5.00076, 4.2659);
    glEnd();

    //w1
    glBegin(GL_QUADS);
    glColor3ub(157, 95, 46);
    glVertex2f(4.54382, 5.81394);
    glVertex2f(4.47331, 5.80324);
    glVertex2f(4.46655, 5.50011);
    glVertex2f(4.55288, 5.55278);
    glEnd();

    //w2
    glBegin(GL_QUADS);
    glColor3ub(157, 95, 46);
    glVertex2f(4.53877, 5.46148);
    glVertex2f(4.46152, 5.40437);
    glVertex2f(4.47495, 5.10038);
    glVertex2f(4.54549, 5.16756);
    glEnd();

    //w3
    glBegin(GL_QUADS);
    glColor3ub(157, 95, 46);
    glVertex2f(4.6513, 5.20115);
    glVertex2f(4.57572, 5.12389);
    glVertex2f(4.57404, 4.84677);
    glVertex2f(4.65634, 4.91731);
    glEnd();

    //w4
    glBegin(GL_QUADS);
    glColor3ub(157, 95, 46);
    glVertex2f(4.7508, 5.3096);
    glVertex2f(4.68689, 5.25076);
    glVertex2f(4.6879, 4.97075);
    glVertex2f(4.75892, 5.02554);
    glEnd();

    //w5
    glBegin(GL_QUADS);
    glColor3ub(157, 95, 46);
    glVertex2f(4.8197, 4.67698);
    glVertex2f(4.74438, 4.60165);
    glVertex2f(4.75239, 4.2747);
    glVertex2f(4.83573, 4.38048);
    glEnd();

    //w6
    glBegin(GL_QUADS);
    glColor3ub(157, 95, 46);
    glVertex2f(4.93349, 4.83083);
    glVertex2f(4.86778, 4.74749);
    glVertex2f(4.87259, 4.43337);
    glVertex2f(4.94631, 4.52472);
    glEnd();


}

void BatmanSignal() {
    glBegin(GL_POLYGON);
    glColor3ub(183, 160, 56);
    glVertex2f(3.58, 8.98);
    glVertex2f(3.31, 8.9);
    glColor3ub(64, 58, 37);
    glVertex2f(1.99, 10.92);
    glVertex2f(3.08674, 11.20102);
    glEnd();
    //signal
    circle(0.71, 2.43162, 11.47399, 75, 68, 39);
    //batlogo
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(2.08556, 11.66069);
    glVertex2f(1.73899, 11.47355);
    glVertex2f(1.97235, 11.45275);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(2.08556, 11.66069);
    glVertex2f(1.97235, 11.45275);
    glVertex2f(2.02318, 11.37189);
    glVertex2f(2.10173, 11.58445);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(2.10173, 11.58445);
    glVertex2f(2.02318, 11.37189);
    glVertex2f(2.22067, 11.37586);
    glVertex2f(2.22188, 11.48972);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(2.22067, 11.37586);
    glVertex2f(2.22188, 11.48972);
    glVertex2f(2.35207, 11.43334);
    glVertex2f(2.3808, 11.28138);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(2.35207, 11.43334);
    glVertex2f(2.3808, 11.28138);
    glVertex2f(2.48171, 11.29389);
    glVertex2f(2.47967, 11.44378);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(2.39177, 11.47299);
    glVertex2f(2.35207, 11.43334);
    glVertex2f(2.47967, 11.44378);
    glVertex2f(2.43162, 11.47399);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(2.37926, 11.52821);
    glVertex2f(2.35207, 11.43334);
    glVertex2f(2.39177, 11.47299);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(2.43162, 11.47399);
    glVertex2f(2.43657, 11.53238);
    glVertex2f(2.47967, 11.44378);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(2.47967, 11.44378);
    glVertex2f(2.48171, 11.29389);
    glVertex2f(2.62235, 11.41161);
    glVertex2f(2.59973, 11.52276);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(2.59973, 11.52276);
    glVertex2f(2.62235, 11.41161);
    glVertex2f(2.82007, 11.44604);
    glVertex2f(2.70006, 11.62998);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(2.70938, 11.71845);
    glVertex2f(2.70006, 11.62998);
    glVertex2f(2.82007, 11.44604);
    glVertex2f(2.86187, 11.52438);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 0, 0);
    glVertex2f(2.70938, 11.71845);
    glVertex2f(2.86187, 11.52438);
    glVertex2f(3.09291, 11.57752);
    glEnd();
}

void GCPD() {
    //roof
    glBegin(GL_POLYGON);
    glColor3ub(112, 62, 51);
    glVertex2f(4.48297, 8.68795);
    glVertex2f(3.4742, 8.71427);
    glVertex2f(2.71653, 8.60806);
    glVertex2f(3.77284, 8.57551);
    glEnd();
    //batsignalcircle
    circle(0.14, 3.44408, 8.9389, 42, 36, 44);
    //batsignal base
    glBegin(GL_POLYGON);
    glColor3ub(41, 30, 31);
    glVertex2f(3.52468, 8.70803);
    glVertex2f(3.36497, 8.71002);
    glVertex2f(3.23792, 8.68226);
    glVertex2f(3.23372, 8.61494);
    glVertex2f(3.6576, 8.61627);
    glVertex2f(3.65499, 8.6822);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(63, 44, 45);
    glVertex2f(3.51822, 8.81945);
    glVertex2f(3.37, 8.82);
    glVertex2f(3.36497, 8.71002);
    glVertex2f(3.52468, 8.70803);
    glEnd();

    //ledge front
    glBegin(GL_POLYGON);
    glColor3ub(36, 26, 28);
    glVertex2f(3.83093, 8.0086);
    glVertex2f(2.05739, 8.04555);
    glVertex2f(2.05739, 7.81646);
    glVertex2f(3.83093, 7.79799);
    glEnd();
    //ledge side
    glBegin(GL_POLYGON);
    glColor3ub(71, 47, 42);
    glVertex2f(4.72509, 8.27093);
    glVertex2f(3.83093, 8.0086);
    glVertex2f(3.83093, 7.79799);
    glVertex2f(4.72879, 8.13792);
    glEnd();
    //buildingFront
    glBegin(GL_POLYGON);
    glColor3ub(38, 31, 31);
    glVertex2f(3.83093, 7.79799);
    glVertex2f(2.17, 7.82);
    glVertex2f(2.18552, 5.18176);
    glVertex2f(3.86875, 5.14393);
    glEnd();
    //buildingside
    glBegin(GL_POLYGON);
    glColor3ub(58, 41, 37);
    glVertex2f(4.6, 8.09);
    glVertex2f(3.83093, 7.79799);
    glVertex2f(3.86875, 5.14393);
    glVertex2f(4.64537, 5.36684);
    glEnd();
    //ledge roof
    glBegin(GL_POLYGON);
    glColor3ub(33, 28, 32);
    glVertex2f(4.72509, 8.27093);
    glVertex2f(4.49224, 8.28727);
    glVertex2f(2.05739, 8.04555);
    glVertex2f(3.83093, 8.0086);
    glEnd();
    //roofside
    glBegin(GL_POLYGON);
    glColor3ub(91, 58, 50);
    glVertex2f(4.48297, 8.68795);
    glVertex2f(3.83119, 8.59);
    glVertex2f(3.83093, 8.0086);
    glVertex2f(4.48861, 8.22731);
    glEnd();
    //w1
    glBegin(GL_POLYGON);
    glColor3ub(237, 214, 155);
    glVertex2f(4.02356, 8.58128);
    glVertex2f(3.89909, 8.56737);
    glVertex2f(3.90081, 8.06304);
    glVertex2f(4.02161, 8.09421);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(58, 44, 45);
    glVertex2f(3.96, 8.57);
    glVertex2f(3.97, 8.08);
    glEnd();
    //w2
    glBegin(GL_POLYGON);
    glColor3ub(237, 214, 155);
    glVertex2f(4.20457, 8.6149);
    glVertex2f(4.15565, 8.61153);
    glVertex2f(4.15228, 8.1409);
    glVertex2f(4.20457, 8.14427);
    glEnd();
    //w3
    glBegin(GL_POLYGON);
    glColor3ub(237, 214, 155);
    glVertex2f(4.2653, 8.63177);
    glVertex2f(4.26867, 8.1662);
    glVertex2f(4.31759, 8.1797);
    glVertex2f(4.32265, 8.63852);
    glEnd();
    //w4
    glBegin(GL_POLYGON);
    glColor3ub(237, 214, 155);
    glVertex2f(4.46603, 8.66888);
    glVertex2f(4.38, 8.65876);
    glVertex2f(4.37832, 8.20331);
    glVertex2f(4.47109, 8.22018);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(58, 44, 45);
    glVertex2f(4.42, 8.66);
    glVertex2f(4.43, 8.21);
    glEnd();

    //windowfronts
    //w1 
    glBegin(GL_POLYGON);
    glColor3ub(237, 214, 155);
    glVertex2f(2.53088, 7.68107);
    glVertex2f(2.33723, 7.68617);
    glVertex2f(2.32859, 6.98949);
    glVertex2f(2.5229, 6.98576);
    glEnd();

    //w2
    glBegin(GL_POLYGON);
    glColor3ub(237, 214, 155);
    glVertex2f(3.03, 7.68);
    glVertex2f(2.82, 7.68);
    glVertex2f(2.83, 6.97);
    glVertex2f(3.05, 6.96);
    glEnd();

    //w3
    glBegin(GL_POLYGON);
    glColor3ub(237, 214, 155);
    glVertex2f(3.5, 7.69);
    glVertex2f(3.32, 7.7);
    glVertex2f(3.31, 6.94);
    glVertex2f(3.51, 6.94);
    glEnd();

    //w4
    glBegin(GL_POLYGON);
    glColor3ub(237, 214, 155);
    glVertex2f(3.49644, 6.82179);
    glVertex2f(3.3, 6.83);
    glVertex2f(3.28, 6.24);
    glVertex2f(3.5, 6.22);
    glEnd();

    //w5
    glBegin(GL_POLYGON);
    glColor3ub(237, 214, 155);
    glVertex2f(2.49, 6.8);
    glVertex2f(2.3, 6.8);
    glVertex2f(2.31, 6.28);
    glVertex2f(2.5, 6.27);
    glEnd();

    //w6
    glBegin(GL_POLYGON);
    glColor3ub(237, 214, 155);
    glVertex2f(4.03, 7.78);
    glVertex2f(3.92, 7.75);
    glVertex2f(3.94, 7.07);
    glVertex2f(4.06, 7.09);
    glEnd();
    //w6
    glBegin(GL_POLYGON);
    glColor3ub(237, 214, 155);
    glVertex2f(4.46, 7.92);
    glVertex2f(4.37, 7.9);
    glVertex2f(4.4, 7.2);
    glVertex2f(4.49, 7.24);
    glEnd();
    //w7
    glBegin(GL_POLYGON);
    glColor3ub(237, 214, 155);
    glVertex2f(4.52, 7.07);
    glVertex2f(4.43, 7.02);
    glVertex2f(4.42, 6.33);
    glVertex2f(4.53, 6.38);
    glEnd();

    //roofFront
    glBegin(GL_POLYGON);
    glColor3ub(27, 25, 30);
    glVertex2f(3.83123, 8.59049);
    glVertex2f(2.27769, 8.5972);
    glVertex2f(2.21334, 8.06255);
    glVertex2f(3.8294, 8.00506);
    glEnd();

    //G
    glBegin(GL_POLYGON);
    glColor3ub(189, 120, 63);
    glVertex2f(2.48574, 8.59784);
    glVertex2f(2.27769, 8.5972);
    glVertex2f(2.16383, 8.50314);
    glVertex2f(2.25942, 8.46657);
    glVertex2f(2.48066, 8.46849);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(189, 120, 63);
    glVertex2f(2.25942, 8.46657);
    glVertex2f(2.16383, 8.50314);
    glVertex2f(2.15393, 8.17641);
    glVertex2f(2.25942, 8.18593);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(189, 120, 63);
    glVertex2f(2.25942, 8.18593);
    glVertex2f(2.15393, 8.17641);
    glVertex2f(2.21688, 8.04743);
    glVertex2f(2.44112, 8.04842);
    glVertex2f(2.50728, 8.12646);
    glVertex2f(2.39701, 8.18583);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(189, 120, 63);
    glVertex2f(2.51013, 8.34932);
    glVertex2f(2.39713, 8.34932);
    glVertex2f(2.39701, 8.18583);
    glVertex2f(2.50728, 8.12646);
    glEnd();
    //c
    glBegin(GL_POLYGON);
    glColor3ub(189, 120, 63);
    glVertex2f(2.91722, 8.59452);
    glVertex2f(2.67088, 8.59452);
    glVertex2f(2.70239, 8.45131);
    glVertex2f(2.91435, 8.45274);

    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(189, 120, 63);
    glVertex2f(2.70239, 8.45131);
    glVertex2f(2.67088, 8.59452);
    glVertex2f(2.58638, 8.50716);
    glVertex2f(2.58782, 8.12477);
    glVertex2f(2.6537, 8.03597);
    glVertex2f(2.70526, 8.1749);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(189, 120, 63);
    glVertex2f(2.91214, 8.17385);
    glVertex2f(2.70526, 8.1749);
    glVertex2f(2.6537, 8.03597);
    glVertex2f(2.91006, 8.035);
    glEnd();
    //p
    glBegin(GL_POLYGON);
    glColor3ub(189, 120, 63);
    glVertex2f(3.11785, 8.19208);
    glVertex2f(3.27149, 8.19208);
    glVertex2f(3.3457, 8.26499);
    glVertex2f(3.3444, 8.49805);
    glVertex2f(3.27149, 8.57617);
    glVertex2f(3.00588, 8.57877);
    glVertex2f(3.00588, 8.03584);
    glVertex2f(3.12306, 8.035);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(45, 30, 28);
    glVertex2f(3.23503, 8.4642);
    glVertex2f(3.11004, 8.4668);
    glVertex2f(3.11004, 8.31968);
    glVertex2f(3.23633, 8.32098);
    glEnd();
    //D
    glBegin(GL_POLYGON);
    glColor3ub(189, 120, 63);
    glVertex2f(3.78056, 8.09443);
    glVertex2f(3.77275, 8.49414);
    glVertex2f(3.77275, 8.49414);
    glVertex2f(3.40429, 8.57486);
    glVertex2f(3.4, 8.01);
    glVertex2f(3.71, 8.01);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(189, 120, 63);
    glVertex2f(3.77275, 8.49414);
    glVertex2f(3.70505, 8.57617);
    glVertex2f(3.66208, 8.44467);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(189, 120, 63);
    glVertex2f(3.66208, 8.44467);
    glVertex2f(3.70505, 8.57617);
    glVertex2f(3.40429, 8.57486);
    glVertex2f(3.52147, 8.44727);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(39, 30, 29);
    glVertex2f(3.66208, 8.44467);
    glVertex2f(3.52147, 8.44727);
    glVertex2f(3.52017, 8.16474);
    glVertex2f(3.66078, 8.16214);
    glEnd();
}

void buildingInMiddleInfrontOfBatman() {
    //front
    glBegin(GL_POLYGON);
    glColor3ub(29, 28, 34);
    glVertex2f(-1.59524, 4.29404);
    glVertex2f(-0.2321, 4.17252);
    glVertex2f(-0.19033, 9.87431);
    glVertex2f(-1.5526, 9.85772);
    glEnd();
    //side
    glBegin(GL_POLYGON);
    glColor3ub(38, 30, 35);
    glVertex2f(-0.2321, 4.17252);
    glVertex2f(0.26382, 4.75525);
    glVertex2f(0.25754, 9.84847);
    glVertex2f(-0.19033, 9.87431);
    glEnd();

    //ledge
    glBegin(GL_POLYGON);
    glColor3ub(60, 40, 41);
    glVertex2f(-1.62416, 9.85517);
    glVertex2f(-0.19033, 9.87431);
    glVertex2f(-0.1926, 10.02238);
    glVertex2f(-1.62598, 10.00785);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(60, 40, 41);
    glVertex2f(-0.19033, 9.87431);
    glVertex2f(0.29003, 9.84829);
    glVertex2f(0.29365, 9.98114);
    glVertex2f(-0.1926, 10.02238);
    glEnd();
}

void updateBlimp(int value) {
    if (blimpForward) {
        blimpX += blimpSpeed;
    }
    else {
        blimpX -= blimpSpeed;
    }
    if (blimpX > 4.6) {
        blimpX = -9.0;
    }

    glutPostRedisplay();
    glutTimerFunc(16.66, updateBlimp, 0);
}

void playMusic() {
#ifdef _WIN32
    PlaySound("music.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
#endif
}

void myInit() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-6, 6, 0, 17);
    // glMatrixMode(GL_MODELVIEW);

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    if (saveGotham) {
        sky();
        policeBlimp();
        npcBuildings();
        buildingNextTobuildingWithVerticleWindows();
        buildingWithVerticleWindows();
        wayneTower();
        buildingInMiddleInfrontOfBatman();
        buldingBehindBuildinginfrontbatman();
        Buildinginfrontbatman();
        batmanBuilding();
        BatmanSignal();
        GCPD();
        buildingfrontofgcpd();
        policeBuilding();
        buildingBeforeverticleWindows();
        buildingAboveBottomRight();
        bottomRightbuilding();
        Batman();
        glFlush();
    }
    else
    {
        sky();
        npcBuildings();
        buildingNextTobuildingWithVerticleWindows();
        buildingWithVerticleWindows();
        wayneTower();
        buildingInMiddleInfrontOfBatman();
        buldingBehindBuildinginfrontbatman();
        Buildinginfrontbatman();
        batmanBuilding();
        GCPD();
        buildingfrontofgcpd();
        policeBuilding();
        buildingBeforeverticleWindows();
        buildingAboveBottomRight();
        bottomRightbuilding();
        glFlush();
    }
}

void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
    case 'B':
    case 'b':
        saveGotham = !saveGotham;
        break;
    case 'S':
    case 's':
        blimpSpeed = 0;
        break;
    case 'A':
    case 'a':
        blimpSpeed = 0.001;
        break;
    case 'Z':
    case 'z':
        blimpForward = false; //reverse blimp
        break;
    case 'X':
    case 'x':
        blimpForward = true;
        break;
        glutPostRedisplay();
    }
}

void handleMouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON)
    {
        blimpSpeed += 0.001f;
    }
    if (button == GLUT_RIGHT_BUTTON)
    {
        blimpSpeed -= 0.001f;
    }
    if (blimpSpeed <= 0)
    {
        blimpSpeed = 0;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(750, 1040);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 750) / 2,
        (glutGet(GLUT_SCREEN_HEIGHT) - 1080) / 2);
    glutCreateWindow("Gotham City");
    glutDisplayFunc(display);
    myInit();
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutTimerFunc(0, updateBlimp, 0);
    playMusic();
    glutMainLoop();
    return 0;
}