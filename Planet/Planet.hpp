#ifndef PLANET_H
#define PLANET_H

#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glext.h>

using namespace std;

class Planet{
public:
	float radius, distance, orbit, speed, tilt, axis;
public:
	Planet(float _radius, float _distance, float _orbit, float _speed, float _tilt, float _axis);
};

#endif
