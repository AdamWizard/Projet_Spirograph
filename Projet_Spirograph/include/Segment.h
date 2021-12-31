#ifndef SEGMENT_H
#define SEGMENT_H
#include "Point.h"


class Segment
{
    public:
        Segment(float startX,float startY,float endX,float endY);

        virtual ~Segment();

        getStartX();

        getStartY();

        getEndX();

        getEndY();

    private:
        float startX;
        float startY;
        float endX;
        float endY;
};

#endif // SEGMENT_H
