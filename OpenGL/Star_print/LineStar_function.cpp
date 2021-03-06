#include<GL/glut.h>
#include<GL/gl.h> 
#include<iostream>
using namespace std;
void init()
{
    // Set display window color to as glClearColor(R,G,B,Alpha)
    glClearColor(1.0, 1.0, 1.0, 1.0);
    // Set projection parameters.
    glMatrixMode(GL_PROJECTION);
    // Set 2D Transformation as gluOrtho2D(Min Width, Max Width, Min Height, 		Max Height)
    gluOrtho2D(0.0, 700, 0.0, 700);
}
void print_star(int x,int y)
{
	glColor3f(1,0,0);
	glBegin( GL_LINES ); //LINES not LINE => LINE does not give error but does not render anything!!!
		glVertex2i( x,y-6 );
		glVertex2i( x,y+6 );
	glEnd();
	glFlush();
	glColor3f(1,0,0);
	glBegin( GL_LINES );
		glVertex2i( x-6,y );
		glVertex2i( x+6,y );
	glEnd();
	glFlush();
	glColor3f(1,0,0);
	glBegin( GL_LINES );
		glVertex2i( x-6,y+6 );
		glVertex2i( x+6,y-6 );
	glEnd();
	glFlush();
	glColor3f(1,0,0);
	glBegin( GL_LINES );
		glVertex2i( x-6,y-6 );
		glVertex2i( x+6,y+6 );
	glEnd();
	glFlush();
}
void display()
{
	glClear( GL_COLOR_BUFFER_BIT );	
	int x,y;
	x=350;
	y=350;
	print_star(x,y);
}
int main(int argc, char**argv) 
{
    glutInit(&argc, argv); 
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB ); 
    glutInitWindowSize( 700,700 ); 
    glutCreateWindow("Star"); 
    init(); //Important to initialize 
    glutDisplayFunc(display); 
    glutMainLoop();  //See screen for long time similar to getch
}

