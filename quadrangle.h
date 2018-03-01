#ifndef QUADRANGLE_H
#define QUADRANGLE_H
#include "shape.h"

class Quadrangle : public Shape
{
public:
	//Default constructor
	Quadrangle();
	
	virtual void display();
    virtual void handleEvent(Event *e);
	
	virtual bool isComplete();
    virtual void addPoint(int _x, int _y);
	
private:
	int x1,x2,x3,x4;
	int y1,y2,y3,y4;
	int pointCount;
};
#endif