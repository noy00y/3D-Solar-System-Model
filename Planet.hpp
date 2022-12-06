/*
 * Planet.hpp
 *
 *  Created on: Dec. 6, 2022
 *      Author: Mr. T
 */

#ifndef PLANET_HPP_
#define PLANET_HPP_

#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glext.h>
#include "imageloader.h"
using namespace std;

class Planet{
public:
	float radius, distance, orbit, orbitSpeed, axisTilt, axisAni;
public:
	Planet(float _radius, float _distance, float _orbit, float _orbitSpeed, float _axisTilt, float _axisAni);
};

#endif /* PLANET_HPP_ */
