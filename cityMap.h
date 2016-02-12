#ifndef CITYMAP_H
#define CITYMAP_H
#include "graph.h"
class CityMap
{
private:
    Graph city;
    void addJunction(string);
    void addRoadBetweenJunctions(string, string , double);
    bool hasNeighbour(string , string);
public:
    CityMap();
    bool roadBetweenJunctions(string , string);//
    void shortesDistanceBetweenJunctions(string , string);//
    void shortesDistanceBetweenJunctionsAlt(string , string , list<string>);//
    bool circleAround(string);//
    bool tourTrip();
    bool isJunctionInCenter(string);//
    void findDeadEnds();//

    void printCity();


};
#endif // CITYMAP_H
