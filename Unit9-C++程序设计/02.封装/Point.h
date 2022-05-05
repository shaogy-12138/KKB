#ifndef _POINT_H_
#define _POINT_H_


#include "line.h"

class Point{

friend float Line::getDistance(const Point&a, const Point&b);
private:
	float _x;
	float _y;
public:
	
	Point(float x, float y);
};
#endif