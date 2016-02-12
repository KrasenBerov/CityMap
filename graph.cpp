#include "graph.h"
#include <iostream>
#include <limits.h>
using namespace std;
Graph::Graph()
{
    numberOfVerts = 0;
}
void Graph::addVertex(Vertex * vert)
{
    numberOfVerts++;
    vertices.push_back(vert);
}

void Graph::createEdge(Vertex * _from , Vertex * _to , double _distance)
{
    _from->addEdge(_to , _distance);
}

bool Graph::hasVertex(Vertex * vert)
{
    for(list<Vertex *>::iterator i = vertices.begin() ; i != vertices.end() ; i ++)
        if( (**i).getData() == (*vert).getData())
            return true;
    return false;
}

void Graph::print()
{
    for(list<Vertex * >::iterator i = vertices.begin() ; i != vertices.end() ; i ++)
        (*i)->print();
}
Vertex * Graph::findVertex(string findData)
{
    for(list<Vertex * >::iterator i = vertices.begin() ; i != vertices.end() ; i ++)
        if((**i).getData() == findData)
            return &(**i);
    //cout << "hello" << endl;
}
Vertex * Graph::findVertexNumber(int num){
    list<Vertex * >::iterator i = vertices.begin();
    advance(i , num);
    return &(**i);
}
void Graph::checkForDeadEndVertices(){
    for(list<Vertex* >::iterator i = vertices.begin() ; i != vertices.end() ; i++)
    {
        list<Edge >::iterator j = (*i)->getEdges().begin();
        if((*i)->hasEdges())
            for(int br = 0 ; br < (*i)->getNumberOfEdges()  ; j ++ , br++)
                if(!((*j).getTo()->hasEdges()))
                    cout << (*i)->getData() << " to " << (*j).getTo()->getData() << " is a dead end " << endl;
    }
}
int Graph::getNumberOfVerts(){
    return vertices.size();
}
bool Graph::hasNeighbour(string from , string to){
    return findVertex(from)->hasNeighbour(to);
}
int Graph::findIndexForMinDist(double* distances ,bool * areUsed , int mySize){//finds the min value of the unchecked
    int myMin = INT_MAX;
    int min_index;
    for(int i = 0 ; i < mySize ; i++)
        if(areUsed[i] == false && distances[i] <= myMin)
        {
            myMin = distances[i];
            min_index = i;
        }
    /*cout << endl << "this is dist ----------------" << endl;
    for(int i = 0 ; i < mySize ; i ++)
    {
        if(distances[i] == INT_MAX)
            cout << "MAX" << " ";
        else
            cout << distances[i] << " ";
    }
    cout << endl;
    for(int i = 0 ; i < mySize ; i ++)
        cout << areUsed[i] << "   ";
    cout << endl << "----------------------------" << endl;
    cout << "the new min is " << min_index << endl;*/
    return min_index;
}
double Graph::Dijkstra(string from , string to , list<string> closed)
{
    int mySize = vertices.size();
    double dists[mySize];
    bool beenThere[mySize];
    for(int i = 0 ; i < mySize ; i ++)
    {
        dists[i] = INT_MAX;
        if(inList(closed , findVertexNumber(i)->getData()))
            beenThere[i] = true;// if vertex is in list , it will be considered as checked
        else
            beenThere[i] = false;
    }
    dists[findVertexIndex(from)] = 0;// dist to self is 0
    for(int i = 0 ; i < mySize - 1 - closed.size() ; i ++)
    {
        int current = findIndexForMinDist(dists , beenThere , mySize);
        beenThere[current] = true;
        for(int j = 0 ; j < mySize ; j++)
            if(beenThere[j] == false && // not yet checked
               hasNeighbour(findVertexNumber(current)->getData() , findVertexNumber(j)->getData()) && // there is a path between the two vertices
               (dists[current] + distFromTo(findVertexNumber(current)->getData() , findVertexNumber(j)->getData()) < dists[j]))// checks if the current distance is higher than the new possible one
                    dists[j] = dists[current] + distFromTo(findVertexNumber(current)->getData() , findVertexNumber(j)->getData());
    }
    return dists[findVertexIndex(to)];
}
int Graph::findVertexIndex(string tmp)
{
    list<Vertex* >::iterator ind = vertices.begin();
    for(int i = 0 ; i < vertices.size() ; i ++)
        if(tmp == (*ind)->getData())
            return i;
        else
            ind++;
}
double Graph::distFromTo(string from , string to)
{
    return findVertex(from)->distTo(to);
}
bool Graph::inList(list<string> tmpList , string tmp)
{
    for(list<string>::iterator i = tmpList.begin() ; i != tmpList.end() ; i++)
        if((*i) == tmp)
            return true;
    return false;
}
bool Graph::circleAround(string from)
{
    if(findVertex(from)->hasEdges())
        if(Dijkstra((*(findVertex(from)->getEdges().begin())).getTo()->getData(),from) == INT_MAX)
            return false;
        else
            return true;
    return false;
}
