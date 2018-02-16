#include <iostream>
#include <string>
#include "sierpinski.h"
#include "term.h"

using namespace std;

Sierpinski::Sierpinski()
{
    //initially we have no where to go!
    dy = 0;
    pointCount = 0;
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

// A helper function to generate the next starting lines of the triangle
static string nextStartLine(string &line)
{
    string result;

    for(int i=0; i<line.length(); i+=4) {
	//we start a new triangle in several situations.  First,
	//we start at the beginning of the row.  Second, we start
	//one at each " /" and again at each " \", but never at "\/"
	//because that is the shared vertex of two triangles!
	if(i == 0 or (line[i] == '/' and line[i-1]!='\\')
	          or (line[i] == ' ' and line[i-1] == '\\')) {
	    result += "/\\  ";
	} else {
	    result += "    ";
	} 
    
    }

    //always end with a starting apex
    result += "/\\";

    return result;
}


// A helper fnction to generate the next finishing lines of the triangle
static string nextFinishLine(string &line)
{
    string result;
    string slice;
    
    //generate the next line
    for(int i=0; i<line.length(); i+=2) {
	slice = line.substr(i, 2);  //get the next two characters
	if(slice == "/\\") {
	    //finish the triangle
	    result += "/__\\";
	    i+=2;
	} else {
	    //spaces!
	    result += "  ";
	}
    }

    return result;
}


void
Sierpinski::display()
{
    string line;
    int cx;
    int cy;

    //start at the indicated position
    cx=x();
    cy=y();
    
    line ="/\\";  //initial line

    //print the rows out!
    for(int row = 0; row <= rowCount; row++) {
	cout << cursorPosition(cx, cy) << line;

	//generate the next line
	if(row % 2) {
	    line = nextStartLine(line);
	} else {
	    line = nextFinishLine(line);
	}
	
	//generate the next coordinates
	cy += dy;
	cx -= 1;
    }
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
    }


    pointCount++;
}



