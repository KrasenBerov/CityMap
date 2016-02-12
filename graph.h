#ifndef GRAPH_H
#define GRAPH_H
#include "edge.h"
#include <queue>
#include <iostream>
using namespace std;
static list<string> tmpEmpty;
class Graph
{
private:
    list<Vertex *> vertices;
    int numberOfVerts;
    int findIndexForMinDist(double* , bool* , int);

    int findVertexIndex(string);
    bool inList(list<string> , string);
public:
    double Dijkstra(string, string ,list<string> closed = tmpEmpty);
    bool circleAround(string);
    Graph();
    void addVertex(Vertex * );
    void createEdge(Vertex * , Vertex * , double);
    bool hasVertex(Vertex *);
    void print();
    void checkForDeadEndVertices();
    int getNumberOfVerts();
    Vertex * findVertex(string);
    Vertex * findVertexNumber(int);
    bool hasNeighbour(string , string);
    double distFromTo(string , string);
};
#endif // GRAPH_H

