#include <iostream>
#include "sierpinski.h"
#include "term.h"

Sierpinski::Sierpinski()
{
    //initially we have no where to go!
    dy = 0;
    pointCount = 0;
}

void
Sierpinski::display()
{
    //TODO: Display the triangle!
}



void
Sierpinski::handleEvent(Event *event)
{
    //DO NOTHING!
}



bool
Sierpinski::isComplete()
{
    return pointCount == 2;
}


void
Sierpinski::addPoint(int _x, int _y)
{
    //don't add to a complete shape
    if(isComplete()) return;

    if(pointCount == 0) {
	//get the apex point
	x(_x);
	y(_y);
    } else if(pointCount == 1) {
	//get the height point
	rowCount = _y - y();

	//determine which direction we are growing in
	if(rowCount > 0) {
	    dy = 1;
	} else {
	    dy = -1;
	    rowCount = -rowCount;
	}

	//the triangle is complete, generate it!
	generate();
    }


    pointCount++;
}


/*
Something like this:

                 /\
                /__\
               /\  /\
              /__\/__\
             /\      /\
            /__\    /__\
           /\  /\  /\  /\
          /__\/__\/__\/__\
         /\              /\
        /__\            /__\
       /\  /\          /\  /\
      /__\/__\        /__\/__\    
     /\      /\      /\      /\
    /__\    /__\    /__\    /__\
   /\  /\  /\  /\  /\  /\  /\  /\
  /__\/__\/__\/__\/__\/__\/__\/__\
 
*/


void
Sierpinski::generate()
{
    //First we work out how wide this will be. and find the center
    int cols=rowCount;
    if(cols % 2 == 0) {
	cols++;
    }
    int center = cols/2 + 1;
    

    
}
