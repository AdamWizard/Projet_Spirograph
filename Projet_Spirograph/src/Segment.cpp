#include "Segment.h"
#include "SFML/Graphics.hpp"

Segment::Segment(float startX,float startY,float endX,float endY)
{
    this.startX=startX;
    this.startY=startY;
    this.endX=endX;
    this.endY=endY;
}

Segment::~Segment()
{

}
