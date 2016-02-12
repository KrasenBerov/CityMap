#include "vertex.h"
#include <iostream>

Vertex::Vertex(string _data)
{
    data = _data;
}

void Vertex::addEdge(Vertex * _vert , double _distance)
{
    Edge newEdge(this , _vert , _distance);
    edges.push_back(newEdge);
}

string Vertex::getData()
{
    return data;
}

list<Edge > Vertex::getEdges()
{
    return edges;
}

void Vertex::print()
{
    cout << "this is " << data << endl;
    for(list<Edge >::iterator i = edges.begin() ; i != edges.end() ; i++)
        cout << "distance from " << data << " to " << i->getTo()->getData() << " is " << i->getDistance() << endl;
}
bool Vertex::hasEdges()
{
    return !edges.empty();
}
int Vertex::getNumberOfEdges()
{
    return edges.size();
}
bool Vertex::hasNeighbour(string neightbour)
{
    for(list<Edge>::iterator i = edges.begin() ; i != edges.end() ; i ++)
        if((*i).getTo()->getData() == neightbour)
            return true;
    return false;
}
double Vertex::distTo(string to)
{
    for(list<Edge>::iterator i = edges.begin() ; i != edges.end() ; i ++)
        if(to == (*i).getTo()->getData())
            return (*i).getDistance();
}
