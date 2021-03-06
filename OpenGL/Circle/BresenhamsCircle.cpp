#include<GL/glut.h>
#include<GL/gl.h>
#include<iostream>
#include<math.h>
using namespace std;
int r;
void init()
{
glClearColor(0.0,0.0,1.0,1.0); //Blue background
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0,700,0,700);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
		int x,y,p,c=0,x1,y1;
	x=350; //x = xc
	y=350+r; //y = yc+r
	p = 3-2*r; //Initial Decision Parameter
	do
	{
x1=700-x;
y1=700-y;
		glColor3f(0,1,0);
		glBegin(GL_POINTS);
		glVertex2d(x,y);
glVertex2d(x,y1);
glVertex2d(x1,y);
glVertex2d(x1,y1);
glVertex2d(y,x);
glVertex2d(y,x1);
glVertex2d(y1,x);
glVertex2d(y1,x1);
		glEnd();
		glFlush();
	if(p<0)
	{
		p = p + 4*x + 6;
	}
	else
	{
		p = p + 4*x - 4*y + 10;
		y--;
	}
	x++;
c++;
if(c==100) //No infinite loop
{
break;
}
	}while(x!=y);
	glColor3f(0,1,0);
		glBegin(GL_POINTS);
		glVertex2d(x,y);
glVertex2d(x,y1);
glVertex2d(x1,y);
glVertex2d(x1,y1);
glVertex2d(y,x);
glVertex2d(y,x1);
glVertex2d(y1,x);
glVertex2d(y1,x1);
		glEnd();
		glFlush();
}
int main(int argc,char **argv)
{
	cout<<"Enter the radius: ";
	cin>>r;
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(700,700);
glutCreateWindow("Bresenhams Circle");
init();
glutDisplayFunc(display);
glutMainLoop();
}
