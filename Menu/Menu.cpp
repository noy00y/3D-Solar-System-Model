#include "menu.hpp"

extern int bigOrbitActive;
extern int changeCamera;
extern int isAnimate;

void menu() {
	glutCreateMenu(mainMenu);
	glutAddMenuEntry("Show Orbit Rings", 1);
	glutAddMenuEntry("Hide Orbit Rings", 2);
	glutAddMenuEntry("View 1", 3);
	glutAddMenuEntry("View 2", 4);
	glutAddMenuEntry("Play Animation", 5);
	glutAddMenuEntry("Stop Animation", 6);
	glutAddMenuEntry("Quit", 7);
}

void mainMenu(GLint option){
	switch (option){
	case 1:
		bigOrbitActive = 1;
		break;
	case 2:
		bigOrbitActive = 0;
		break;
	case 3:
		changeCamera = 0;
		break;
	case 4:
		changeCamera = 1;
		break;
	case 5:
		isAnimate = 0;
		break;
	case 6:
		isAnimate = 1;
		animate(1);
		break;
	case 7:
		exit(0);
	}

}
