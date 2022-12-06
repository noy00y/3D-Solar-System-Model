/*
 * menu.cpp
 *
 *  Created on: Dec. 6, 2022
 *      Author: Mr. T
 */

#include "menu.hpp"

extern int bigOrbitActive;
extern int changeCamera;

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
		exit(0);
	}

}
