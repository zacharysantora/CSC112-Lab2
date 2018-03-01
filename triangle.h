#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <vector>
#include "shape.h"

 class triangle : public Shape
 {
 public:
 	//Default constructor
 	triangle();
 	
	virtual void display();
    virtual void handleEvent(Event *e);
 	
 	virtual bool isComplete();
    virtual void addPoint(int _x, int _y);
 	
 private:
 	int x1,x2,x3,x4,l;
 	int y1,y2,dy,c;
 	int pointCount;
 };
 #endif 