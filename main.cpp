#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glext.h>
#include "Image_Handler/Image_Handler.hpp"
#include "Planet/Planet.hpp"
#include "Menu/Menu.hpp"

using namespace std;



int showRotation = 0;
int rotationLines = 0;
int camAngle = 0;




int dist = 60;
int scene = 0;



Planet sun(2.5, 0, 0, 0, 0, 0);
Planet earth(1.0, -16, 0, 2.98, 23.44, 0);
Planet venus(0.75, 11, 0, 3.50, 177.0, 0);
Planet mars(0.6, 21, 0, 2.41, 25.00, 0);
Planet mercury(0.5, -7, 0, 4.74, 02.11, 0);
Planet jupiter(1.5, -28, 0, 1.31, 03.13, 0);
Planet saturn(1.4, 37, 0, 0.97, 26.70, 0);
Planet uranus(1.25, -45.5, 0, 0.68, 97.77, 0);
Planet neptune(1.1, 53.6, 0, 0.54, 28.32, 0);
Planet pluto(0.15, -59, 0, 0.47, 119.6, 0);




GLuint sunTexture, mercuryTexture, venusTexture, earthTexture, marsTexture, jupiterTexture, saturnTexture, uranusTexture, neptuneTexture, plutoTexture, staTexture, logTexture;

GLuint createTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);


	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->sizeX, image->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image->data);
	return textureId;
}
void setup(){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	Image* sta = loadTexture("textures/stars.bmp");		staTexture = createTexture(sta);		delete sta;
	Image* sun = loadTexture("textures/sun.bmp");		sunTexture = createTexture(sun);		delete sun;
	Image* mercury = loadTexture("textures/mercury.bmp");	mercuryTexture = createTexture(mercury);		delete mercury;
	Image* venus = loadTexture("textures/venus.bmp");		venusTexture = createTexture(venus);		delete venus;
	Image* earth = loadTexture("textures/earth.bmp");		earthTexture = createTexture(earth);		delete earth;
	Image* mars = loadTexture("textures/mars.bmp");		marsTexture = createTexture(mars);		delete mars;


	Image* jupiter = loadTexture("textures/jupiter.bmp");	jupiterTexture = createTexture(jupiter);		delete jupiter;
	Image* saturn = loadTexture("textures/saturn.bmp");		saturnTexture = createTexture(saturn);		delete saturn;
	Image* uranus = loadTexture("textures/uranus.bmp");		uranusTexture = createTexture(uranus);		delete uranus;
	Image* neptune = loadTexture("textures/neptune.bmp");	neptuneTexture = createTexture(neptune);		delete neptune;
	Image* pluto = loadTexture("textures/pluto.bmp");		plutoTexture = createTexture(pluto);		delete pluto;

}

void rotat(){
	glPushMatrix();
	glColor3ub(255, 255, 255);
	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glutWireTorus(0.001, mercury.distance, 100.0, 100.0);
	glutWireTorus(0.001, venus.distance, 100.0, 100.0);
	glutWireTorus(0.001, earth.distance, 100.0, 100.0);
	glutWireTorus(0.001, mars.distance, 100.0, 100.0);
	glutWireTorus(0.001, jupiter.distance, 100.0, 100.0);
	glutWireTorus(0.001, saturn.distance, 100.0, 100.0);
	glutWireTorus(0.001, uranus.distance, 100.0, 100.0);
	glutWireTorus(0.001, neptune.distance, 100.0, 100.0);
	glutWireTorus(0.001, pluto.distance, 100.0, 100.0);
	glPopMatrix();
}
void drawPlanet(Planet planet, GLUquadric *qua, int planetTexture){
	glPushMatrix();
	glRotatef(planet.orbit, 0.0, 1.0, 0.0);
	glTranslatef(planet.distance, 0.0, 0.0);

	glPushMatrix();
	glRotatef(planet.tilt, 1.0, 0.0, 0.0);
	glRotatef(planet.axis, 0.0, 1.0, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, planetTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	gluQuadricTexture(qua, 1);
	gluSphere(qua, planet.radius, 20.0, 20.0);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPopMatrix();

}
void drawScene(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	if (camAngle == 1)gluLookAt(0.0, dist, 50.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	if (camAngle == 0)gluLookAt(0.0, 0.0, dist, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	if (rotationLines == 1) rotat();
	GLUquadric *qua;
	qua = gluNewQuadric();

	// Draws all of the planets
	drawPlanet(mars, qua, marsTexture);
	drawPlanet(earth, qua, earthTexture);
	drawPlanet(sun, qua, sunTexture);
	drawPlanet(venus, qua, venusTexture);
	drawPlanet(mercury, qua, mercuryTexture);
	drawPlanet(jupiter, qua, jupiterTexture);
	drawPlanet(uranus, qua, uranusTexture);
	drawPlanet(neptune, qua, neptuneTexture);
	drawPlanet(pluto, qua, plutoTexture);

	// Draws saturn and its rings
	glPushMatrix();
	glRotatef(saturn.orbit, 0.0, 1.0, 0.0);
	glTranslatef(saturn.distance, 0.0, 0.0);
	glPushMatrix();
	glRotatef(saturn.tilt, 1.0, 0.0, 0.0);
	glRotatef(saturn.axis, 0.0, 1.0, 0.0);
	glRotatef(90.0, 1.0, 0.0, 0.0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, saturnTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	gluQuadricTexture(qua, 1);
	gluSphere(qua, saturn.radius, 20.0, 20.0);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glPushMatrix();
	glColor3ub(170, 135, 134);
	glRotatef(-63.0, 1.0, 0.0, 0.0);


	glutWireTorus(0.2, 6.0, 25.0, 25.0);
	glutWireTorus(0.4, 5.0, 25.0, 25.0);
	glPopMatrix();
	glPopMatrix();
	glColor3ub(255, 255, 255);

	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, staTexture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glBegin(GL_POLYGON);
	glTexCoord2f(-1.0, 0.0); glVertex3f(-200, -200, -100);
	glTexCoord2f(2.0, 0.0); glVertex3f(200, -200, -100);
	glTexCoord2f(2.0, 2.0); glVertex3f(200, 200, -100);
	glTexCoord2f(-1.0, 2.0); glVertex3f(-200, 200, -100);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, staTexture);
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0, 0.0); glVertex3f(-200, -83, 200);
	glTexCoord2f(8.0, 0.0); glVertex3f(200, -83, 200);
	glTexCoord2f(8.0, 8.0); glVertex3f(200, -83, -200);
	glTexCoord2f(0.0, 8.0); glVertex3f(-200, -83, -200);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glutSwapBuffers();
}



void resize(int w, int h){
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-4.0, 4.0, -4.0, 4.0, 4.0, 180.0);
	glMatrixMode(GL_MODELVIEW);
}
void draw(void){
	drawScene();
}
void animate(int n){
	if (showRotation){
		mercury.orbit += mercury.speed;

		mars.orbit += mars.speed;
		jupiter.orbit += jupiter.speed;
		venus.orbit += venus.speed;
		earth.orbit += earth.speed;

		saturn.orbit += saturn.speed;
		uranus.orbit += uranus.speed;
		neptune.orbit += neptune.speed;
		pluto.orbit += pluto.speed;

		if (mercury, venus, earth, mars, jupiter, saturn, uranus, neptune, pluto.orbit  > 360.0){
			mercury, venus, earth, mars, jupiter, saturn, uranus, neptune, pluto.orbit -= 360.0;
		}

		earth.axis += 12.0;
		mars.axis += 12.0;
		jupiter.axis += 12.0;
		saturn.axis += 12.0;


		mercury.axis += 12.0;
		venus.axis += 12.0;
		uranus.axis += 12.0;

		neptune.axis += 12.0;
		pluto.axis += 12.0;
		if (mercury, venus, earth, mars, jupiter,
			saturn, uranus, neptune, pluto.axis > 360.0){
			mercury, venus, earth, mars, jupiter,
			saturn, uranus, neptune, pluto.axis -= 360.0;
		}
		glutPostRedisplay();
		glutTimerFunc(30, animate, 1);
	}
}

void mouseButton(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		if (scene) scene = 0;
	glutPostRedisplay();
}

void scroll(int wheel, int direction, int x, int y)
{
	if (direction > 0 && dist < 100) dist++;
	if (direction < 0 && dist > -75) dist--;
	glutPostRedisplay();
}

void keyboar(unsigned char key, int x, int y){
	switch (key){
	case 1: exit(0); break;
	case '1': if (showRotation) showRotation = 0; else{ showRotation = 1; animate(1); } break;
	}
}



int main(int argc, char **argv){

	glutInit(&argc, argv);

	glutInitContextVersion(4, 2);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(500, 0);
	glutCreateWindow("Solar System");
	glutDisplayFunc(draw);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboar);
	glutMouseWheelFunc(scroll);
	glutMouseFunc(mouseButton);

	glewExperimental = GL_TRUE;
	glewInit();
	cout << "Press 1 to show rotation" << endl;
	cout << "ESC to exit" << endl;
	cout << "Right click to show the menu for more options." << endl;
	menu();
	setup();
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
}
