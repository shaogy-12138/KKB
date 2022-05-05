/*************************************************************************
	> File Name: friend.cpp
	> Author: Jason.shao
	> Mail: shaogy12138@163.com 
	> Created Time: Thu 05 May 2022 11:14:37 PM CST
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;

class Point;
class Line{

	public:
		float getDistance(const Point & a, const Point & b);
};

class Point{


private:
	float _x;
	float _y;
public:
	friend class Line;
	
	Point(float x, float y){
		this->_x = x;
		this->_y = y;
	}
	friend float getDistance(const Point & a, const Point & b){
	return sqrt((a._x - b._x) * (a._x - b._x) + (a._y - b._y) * (a._y - b._y));
}
	friend float Line::getDistance(const Point & a, const Point & b);
};

float Line::getDistance(const Point & a, const Point & b){
	return sqrt((a._x - b._x) * (a._x - b._x) + (a._y - b._y) * (a._y - b._y));
}	

// float getDistance(const Point & a, const Point & b){
// 	return sqrt((a._x - b._x) * (a._x - b._x) + (a._y - b._y) * (a._y - b._y));
// }
int main(){

	Point p1(1.2f, 2.5f), p2(1.2f, 1.6f);
	cout<<getDistance(p1, p2)<<endl;
	Line line;
	cout<<"line.getDestance : "<< line.getDistance(p1, p2)<<endl;
	return 0;
}
