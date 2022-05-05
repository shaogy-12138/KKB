#include "line.h"
#include "Point.h"
#include <cmath>

float Line::getDistance(const Point & a, const Point & b){
    return sqrt((a._x - b._x) * (a._x - b._x) + (a._y - b._y) * (a._y - b._y));
}