#include "menu.hpp"

extern int rotationLines;
extern int camAngle;

void menu() {
	glutCreateMenu(mainMenu);
	glutAddMenuEntry("Show Orbit Rings", 1);
	glutAddMenuEntry("Hide Orbit Rings", 2);
	glutAddMenuEntry("View 1", 3);
	glutAddMenuEntry("View 2", 4);
	glutAddMenuEntry("Quit", 5);
}

void mainMenu(GLint option){
	switch (option){
	case 1:
		rotationLines = 1;
		break;
	case 2:
		rotationLines = 0;
		break;
	case 3:
		camAngle = 0;
		break;
	case 4:
		camAngle = 1;
		break;
	case 5:
		exit(0);
	}

}
