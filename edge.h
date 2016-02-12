#ifndef EDGE_H
#define EDGE_H
#include "vertex.h"
class Vertex;
class Edge
{
private:
    Vertex * from;
    Vertex * to;
    double distance;
public:
    Edge(Vertex * , Vertex * , double);
    Vertex * getFrom();
    Vertex * getTo();
    double getDistance();

};
#endif // EDGE_H

