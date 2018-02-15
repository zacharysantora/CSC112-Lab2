#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle : public Shape
{
    public:
    //default constructor
        Rectangle(); //public constuctor

            virtual void addPoint(int _x, int _y);


        virtual void display();
        virtual void handleEvent(Event *e);

        virtual bool isComplete();

    private:

        int x1,y1;
        int x2,y2;
        int pointCount;
    };
    #endif

