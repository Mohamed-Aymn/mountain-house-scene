#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

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
        glVertex2f(10*cos(angle), 10*sin(angle)+100);
    }
    glEnd();
}


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


void display(void)
{
    /**
    ** global variables
    **/
    float ground = 15; //float [] FLOOR = [100, 15, 100]; // clock wise arrangement
    float greenTreeColor[3] = {0.04, 0.43, 0.03};

    /**
    ** elements
    ** most elements functions have x,y,r,g,b parameters
    ** (x,y): position
    ** (r,g,b): colors
    **/
    sky();
    Tree(0, 10, greenTreeColor[0], greenTreeColor[1], greenTreeColor[2]);
    Tree(100, 10, greenTreeColor[0], greenTreeColor[1], greenTreeColor[2]);
    sun(0,0, 0.92, 0.89, 0.47);


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

    glutCreateWindow("Giza pyramids");

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
