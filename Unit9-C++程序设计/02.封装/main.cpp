#include<iostream>
#include "line.h"
#include "Point.h"


int main(){

    Point p1(1.2f, 2.5f), p2(1.2f, 1.6f);
	//std::cout<<getDistance(p1, p2)<<std::endl;
	Line line;
	std::cout<<"line.getDestance : "<< line.getDistance(p1, p2)<<std::endl;

    return 0;
}