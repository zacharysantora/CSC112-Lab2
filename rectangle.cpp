#include iostream
#include "point.h"
#include "rectangle.h"


using namespace std;
Rectangle::Rectangle()
{
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
    //do nothing
}

//when user presses r = x1,y1 coordinate
//when user presses r again = x2,y2 coordinate



//line function (x1,y1) to (x1,y2)
//line function (x1,y2) to (x2,y2) 
//line function (x2,y2) to (x2,y1)
//line function (x2,y2) to (x1,y1)

//return 0;

