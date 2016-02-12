#include "cityMap.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;
int main()
{

    CityMap c;
    c.printCity();
    c.findDeadEnds();
    cout << c.isJunctionInCenter("First") << endl;
    cout << c.isJunctionInCenter("Second") << endl;
    //cout << c.hasNeighbour("First" , "Seventh") << endl;
    c.shortesDistanceBetweenJunctions("First" , "Fourth");
    list<string> tmp;
    tmp.push_back("Third");
    tmp.push_back("Seventh");
    //c.shortesDistanceBetweenJunctions("First" , "Fourth");
    c.shortesDistanceBetweenJunctionsAlt("First" , "Fourth" , tmp);
    cout << c.circleAround("Eight");
}

