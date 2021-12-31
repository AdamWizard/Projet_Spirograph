#ifndef SHAPE_H
#define SHAPE_H
#include "Disc."
#include "Segment.h"


class Shape
{
    public:
        Shape();
        virtual ~Shape();

    private:
        Disc* listDiscs;
        Segment* listSegments;
};

#endif // SHAPE_H
