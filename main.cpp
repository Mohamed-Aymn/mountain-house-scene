#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>
#include <iostream>

void sky(){
    glClear(GL_COLOR_BUFFER_BIT);
}

void sun(float x, float y, float r, float g, float b){
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    // used algorithm in section material :)
    float angle;
    for(int i = 0; i < 360; i++){
        angle = i*3.14/180;
        glVertex2f(10*cos(angle)+x, 10*sin(angle)+y);
    }
    glEnd();
}

void ground(float height, float r, float g, float b){
    glColor3f(r, g, b);

    glBegin(GL_POLYGON);
    glVertex2i(0, 0);
    glVertex2i(0, height);
    glVertex2i(100, height);
    glVertex2i(100, 0);
    glEnd();
}


void mountain(float x, float y, float height, float width, float r, float g, float b){
    // left triangle
    glColor3f(r, g, b);

    // mountain structure
    float midpoint = (x+x+width)/2;
    std::cout << midpoint;
    glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(midpoint, y + height);
    glVertex2i(x+width, y);
    glEnd();
}

/*
    glBegin(GL_POLYGON);
    float angle;
    for(int i = 0; i < 360; i++){
        angle = i*3.14/180;
        glVertex2f(3*cos(angle)+midpoint, 3*sin(angle)+ (y + height-11));
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++){
        angle = i*3.14/180;
        glVertex2f(3*cos(angle)+(midpoint-6), 3*sin(angle)+ (y + height-11));
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++){
        angle = i*3.14/180;
        glVertex2f(3*cos(angle)+(midpoint+6), 3*sin(angle)+ (y + height-11));
    }
    glEnd();*/

void Tree(float x, float y, float r, float g, float b) {
    glColor3f(r, g, b);
    float scale = 1;
    float size = 15;

    for(int i = 0; i < 3; i++){
        glBegin(GL_POLYGON);

        glVertex2i(x+size/scale, y-size/scale);
        glVertex2i(x, y);
        glVertex2i(x-size/scale, y-size/scale);
        glEnd();

        scale+=0.25;
        y+=9;
    }
}

/*
void cloud(float x, float y, float r, float g, float b) {
    int num_segments = 100;
    float radius = 5.0f;

    glPushMatrix();
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(r, g, b);
    glVertex2f(0.0f, 0.0f); // Center of the circle

    for (int i = 0; i <= num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float dx = radius * cosf(theta);
        float dy = radius * sinf(theta);
        glVertex2f(dx, dy);
    }

    glEnd();

    glPopMatrix();
}
*/


void cloud(float x, float y, float r, float g, float b){
    int num_segments = 100;
    float radius = 5;
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(r, g, b);
    glVertex2f(x, y); // Center of the circle

    for (int j = 0; j < 2; j++){
        for (int i = 0; i <= num_segments; i++) {
            float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
            float dx = radius * cosf(theta);
            float dy = radius * sinf(theta);
            glVertex2f(x + dx, y + dy);
        }
        x+=3;
    }

    glEnd();
}


void house(float x, float y){
    // left part
    glColor3f(0.56, 0.4, 0.51);

    glBegin(GL_POLYGON);
    glVertex2i(x, y);
    glVertex2i(x, y+10);
    glVertex2i(x+5, y+20);
    glVertex2i(x+10, y+10);
    glVertex2i(x+10, y);
    glEnd();

    // right part
    glColor3f(0.43, 0.31, 0.4);

    glBegin(GL_POLYGON);
    glVertex2i(x+10, y);
    glVertex2i(x+20, y);
    glVertex2i(x+20, y+10);
    glVertex2i(x+10, y+10);
    glEnd();

    // right part -- window
    glColor3f(0.8, 0.8, 0);

    glBegin(GL_POLYGON);
    glVertex2i(x+14, y+5);
    glVertex2i(x+16, y+5);
    glVertex2i(x+16, y+8);
    glVertex2i(x+14, y+8);
    glEnd();

    //  roof
    glColor3f(0.72, 0.55, 0.68);

    glBegin(GL_POLYGON);
    glVertex2i(x+10, y+10);
    glVertex2i(x+20, y+10);
    glVertex2i(x+15, y+20);
    glVertex2i(x+5, y+20);
    glEnd();

    // door
    glColor3f(0.56, 0.47, 0.02);

    glBegin(GL_POLYGON);
    glVertex2i(x+3, y);
    glVertex2i(x+3, y+5);
    glVertex2i(x+5, y+7.5);
    glVertex2i(x+7.5, y+5);
    glVertex2i(x+7.5, y);
    glEnd();
}


void display(void)
{
    /**
    ** global variables
    **/
    // float ground = 15; //float [] FLOOR = [100, 15, 100]; // clock wise arrangement
    float groundLevel = 37;
    float greenTreeColor[3] = {0.04, 0.43, 0.03};



    /**
    ** elements
    ** most element functions have these pattern of parameters
    ** position parameters such as (x,y), (x only) or (y only)
    ** color parameters which are always (r,g,b)
    **/
    sky();
    mountain(40, groundLevel, 30, 50, 0.669, 0.594, 0.594);
    // Snow layer
    mountain(56.99, groundLevel+20, 10, 17.125, 1, 1, 1);
    // Snow layer
    mountain(10, groundLevel, 40, 70, 0.769, 0.694, 0.694);
    mountain(32, groundLevel+25.5, 15, 26, 1, 1, 1);


    sun(100, 100, 0.92, 0.89, 0.47);
    cloud(80, 90, 1, 1, 1);
    cloud(20, 90, 1, 1, 1);
    ground(groundLevel, 0.72, 0.84, 0.8);
    house(70, 30);
    Tree(0, 10, greenTreeColor[0], greenTreeColor[1], greenTreeColor[2]);
    Tree(100, 10, greenTreeColor[0], greenTreeColor[1], greenTreeColor[2]);


    /** *************** should be called at the end of the display function *************** **/
    // Performs a buffer swap on the layer in use for the current window. Specifically,
    // glutSwapBuffers promotes the contents of the back buffer of the layer in use of
    // the current window to become the contents of the front buffer. The contents of the
    // back buffer then become undefined. The update typically takes place during the vertical
    // retrace of the monitor, rather than immediately after glutSwapBuffers is called.
    glutSwapBuffers();
    // execute code to the rendering engine
    glFlush();
}


/* Program entry point */

int main(int argc, char *argv[])
{
    // initialize glut library
    glutInit(&argc, argv);

    /*
        Double buffering involves using two buffers, typically referred to as the
        front buffer and the back buffer. The front buffer is the one currently being
        displayed on the screen, while rendering and other operations occur in the back buffer.
    */
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    // window size
    glutInitWindowSize(1200, 800);
    // where it should open
    glutInitWindowPosition(0, 0);

    glutCreateWindow("Mountain scene");

    // Clear Color buffer, sky color
    glClearColor(0.81, 0.92, 0.96, 0);
    // Sets the mode to 2D
    glMatrixMode(GL_PROJECTION);
    // Maps the x,y to logical positions
    gluOrtho2D(0.0, 100.0, 0.0, 100.0);

    glutDisplayFunc(display);
    glutMainLoop();

    return EXIT_SUCCESS;
}
