#include "edge.h"

Edge::Edge(Vertex * _from , Vertex * _to , double _distance)
{
    from = _from;
    to = _to;
    distance = _distance;
}

Vertex * Edge::getFrom()
{
    return from;
}

Vertex * Edge::getTo()
{
    return to;
}

double Edge::getDistance()
{
    return distance;
}

