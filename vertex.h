#ifndef VERTEX_H
#define VERTEX_H
#include "edge.h"
#include <list>
#include <string>
using namespace std;
class Edge;

class Vertex
{
private:
    string data;
    list<Edge> edges;
public:
    Vertex(string);
    void addEdge(Vertex * , double);
    string getData();
    list<Edge > getEdges();
    void print();
    bool operator == (Vertex & );
    bool hasEdges();
    int getNumberOfEdges();
    bool hasNeighbour(string);
    double distTo(string);
};
#endif // VERTEX_H
