#include "cityMap.h"
#include "CityReader.h"
#include <iostream>
#include <limits.h>
using namespace std;
void CityMap::addJunction(string junc)
{
    Vertex * tmp = new Vertex(junc);
    city.addVertex(tmp);
}
void CityMap::addRoadBetweenJunctions(string from , string to , double dist)
{
    city.createEdge(city.findVertex(from), city.findVertex(to) , dist);
}
void CityMap::printCity()
{
    city.print();
}
CityMap::CityMap()
{
    CityReader c;
    while(!c.namesOfJunctions.empty())
    {
        addJunction(c.namesOfJunctions.front());
        c.namesOfJunctions.pop();
    }
    int i = 0;
    while(!c.namesOfToJunctions.empty())
    {
        while(!c.namesOfToJunctions.front().empty())
        {
            addRoadBetweenJunctions(city.findVertexNumber(i)->getData() , c.namesOfToJunctions.front().front().first , c.namesOfToJunctions.front().front().second);
            c.namesOfToJunctions.front().pop();
        }
        i++;
        c.namesOfToJunctions.pop();
    }
}
bool CityMap::isJunctionInCenter(string name)
{
    if(city.getNumberOfVerts() - 1 == city.findVertex(name)->getNumberOfEdges())
        return true;
    return false;
}
void CityMap::findDeadEnds()
{
    cout << "The dead ends are : " << endl;
    city.checkForDeadEndVertices();
    cout << "No more dead ends !" << endl;
}
bool CityMap::hasNeighbour(string from ,string to)
{
    return city.hasNeighbour(from , to);
}
void CityMap::shortesDistanceBetweenJunctions(string from , string to)
{
    cout << "The distance between " << from << " and " << to << " is " << city.Dijkstra(from,to) << endl;
}
void CityMap::shortesDistanceBetweenJunctionsAlt(string from , string to , list<string> closed)
{
    cout << "The distance between " << from << " and " << to << " is " << city.Dijkstra(from,to,closed) << endl;
}
bool CityMap::roadBetweenJunctions(string from , string to)
{
    if(city.Dijkstra(from,to) != INT_MAX)
        return true;
    return false;
}
bool CityMap::circleAround(string from)
{
    return city.circleAround(from);
}
