#include <iostream>
#include <cmath>
#include "shape.h"
#include "term.h"
#include "line.h"
#include "quadrangle.h"

using namespace std;

Quadrangle::Quadrangle()
{
	x1 = -1;
	y1 = -1;
	pointCount = 0;
}

//display
void
Quadrangle::display()
{
	if(not isComplete())
	{
		return;
	}
	
	Line l1,l2,l3,l4;
	l1.addPoint(x1,y1);
	l1.addPoint(x2,y2);
	l1.display();
	
	l2.addPoint(x2,y2);
	l2.addPoint(x3,y3);
	l2.display();
	
	l3.addPoint(x3,y3);
	l3.addPoint(x4,y4);
	l3.display();
	
	l4.addPoint(x4,y4);
	l4.addPoint(x1,y1);
	l4.display();
	
}

void 
Quadrangle::handleEvent(Event *e)
{
	//DON'T DO A THING
}

bool
Quadrangle::isComplete()
{
	return pointCount == 4;
}

void
Quadrangle::addPoint(int _x, int _y)
{
	//don't add to a completed line
	if(isComplete()) return;

	//set the endpoint and mark ourselves complete
	if(pointCount == 0) {
		//set the first end point
		x1 = _x;
		y1 = _y;
		pointCount++;
	} 
	else if(pointCount == 1) {
		//set the first end point
		x2 = _x;
		y2 = _y;
		pointCount++;
	}
	else if(pointCount == 2) {
		//set the first end point
		x3 = _x;
		y3 = _y;
		pointCount++;
	}
	else
	{
		x4 = _x;
		y4 = _y;
		pointCount++;
	}
}