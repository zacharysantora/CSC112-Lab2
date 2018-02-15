<<<<<<< HEAD
=======
//makes a rectangle

>>>>>>> 4fa78b5c061dd2ae96985f5c92fc3dc023fd5e2f
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
    
    l2.addPoint(x1,y1)
    
}
//when user presses r = x1,y1 coordinate
//when user presses r again = x2,y2 coordinate



//line function (x1,y1) to (x1,y2)
//line function (x1,y2) to (x2,y2)
//line function (x2,y2) to (x2,y1)
//line function (x2,y2) to (x1,y1)

//return 0;

