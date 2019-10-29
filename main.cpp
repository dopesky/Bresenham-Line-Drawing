#include<iostream>
#include<GL/glut.h>
#include<math.h>
#include<algorithm>

using namespace std;

int x00;
int y00;
int xEnd;
int yEnd;

void bres()
{
	glLineWidth(5.0);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(x00, y00);
	glVertex2i(xEnd, yEnd);
	glEnd();
	int x, y, rightY;
	x = min(x00, xEnd);
	y = x == x00 ? y00 : yEnd;
	rightY = x == x00 ? yEnd : y00;
	int dx = fabs(xEnd - x00), dy = fabs(yEnd - y00);
	float gradient = (float)dy / (float)dx;
	cout << "The Gradient is: " << (float)(yEnd - y00) / (float)(xEnd - x00) << endl;
	glPointSize(5.0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	if (gradient < 1) {
		int p = 2 * dy - dx;
		while (x < max(x00, xEnd)) {
			x++;
			if (p < 0) {
				p = p + 2 * dy;
			} else {
				if (y < rightY) y++;
				else y--;
				p = p + 2 * dy - 2 * dx;
			}
			glBegin(GL_POINTS);
			glVertex2i(x, y);
			glEnd();
		}
	}else{
		int p = 2 * dx - dy;
		while (min(y, rightY) < max(y, rightY)) {
			if (y < rightY) y++;
			else y--;
			if (p < 0) {
				p = p + 2 * dx;
			} else {
				x++;
				p = p - 2 * dy + 2 * dx;
			}
			glBegin(GL_POINTS);
			glVertex2i(x, y);
			glEnd();
		}
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	bres();
	glFlush();

}

int main(int argc, char* argv[])
{
	cout << "Enter the Coordinates for first point: \nX: ";
	cin >> x00;
	cout << "Y: ";
	cin >> y00;
	cout << "Enter the Coordinates for Last Point: \nX: ";
	cin >> xEnd;
	cout << "Y: ";
	cin >> yEnd;

	glutInit(&argc, argv);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Bresenham's Algorithm!");

	glClearColor(1.0, 1.0, 1.0, 1.0);
	gluOrtho2D(-40, 40, -40, 40);
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}