#include iostream
#include "point.h"
#include "rectangle.h"


using namespace std;
Rectangle::Rectangle()
{
		x1 = -1;
		y1 = -1;
		pointCount = 0;
}

void Rectangle::display()
{
    if(not isComplete())
    {
        return;
    }

    Line l1,l2,l3,l4;
    l1.addPoint(x1,y1);
    l1.addPoint(x2,y2);
    l1.display();

    l2.addPoint(x1,y1);
    l2.addPoint(x2,y2);
    l2.display();

    l3.addPoint(x2,y2);
    l3.addPoint(x2,y1);
    l3.display();

    l4.addPoint(x2,y2);
    l4.addPoint(x1,y1);
    l4.display();

}

void
Rectangle::handleEvent(Event *e)
{
<<<<<<< HEAD
    
=======
    //do nothing
}

bool
Rectangle::isComplete()
{
	return pointCount == 2
}

void
Rectangle::addPoint(int_x, int _y)
{
	//dont add to a completed line
	if(isComplete()) return;

	//set endpoint and mark complete
	if(pointCount == 0){
		//set the first end point
		x1 = _x;
		y1 = _y;
		pointCount++;
	}
	else {
		//set the second end point
		x2 = _x;
		y2 = _y;
	}
	
}
<<<<<<< HEAD
return 0;
=======

>>>>>>> 63d1e1a5a5fb6e9275f3b88d23e84f9f23dafae4
>>>>>>> 6bbde798463e8db0bb63a4961c584d66bb5af933
