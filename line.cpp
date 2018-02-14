#include <iostream>
#include <cmath>
#include "shape.h"
#include "term.h"
#include "line.h"

using namespace std;

Line::Line()
{
    //we start an incomplete line!
    _complete = false;
    _ex = -1;
    _ey = -1;
}


//display the line
void
Line::display()
{
    //do not draw incomplete lines
    if(not isComplete()) {
	return;
    }

    //the line is complete!  Draw it!
    double px=ex(), py=ey();  //the current points
    int steps;  //the number of steps needed to draw the line
    int dx, dy; //deltas for x and y

    //work out the number of points along the line and the deltas
    dx = ex() - x();
    dy = ey() - y();
    steps = int(sqrt(pow(dx, 2) + pow(dy, 2)));
    if(steps) {
	dx /= steps;
	dy /= steps;
    }

	  
    //we'll rig the game by drawing the end point
    cout << cursorPosition(ex(), ey()) << "#";

    //and now we'll connect them!
    while(--steps) {
	// print the point and update to the next position
	cout << cursorPosition(int(px), int(py)) << "#";
	px += dx;
	py += dy;
    }

    cout.flush();
}


void
Line::handleEvent(Event *e)
{
    //do nothing
}


//Returns true if the shape is complete
bool
Line::isComplete()
{
    return _complete;
}



void
Line::addPoint(int _x, int _y)
{
    //don't add to a completed line
    if(isComplete()) return;

    //set the endpoint and mark ourselves complete
    _ex = _x;
    _ey = _y;
    _complete = true;
}


//return ex
int
Line::ex()
{
    return _ex;
}


//return ey
int
Line::ey()
{
    return _ey;
}
