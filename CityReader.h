#ifndef CITYREADER_H
#define CITYREADER_H
#include <queue>
#include <string>
using namespace std;
class CityReader
{
public:
    queue<string> namesOfJunctions;
    queue<queue < pair <string , double > > > namesOfToJunctions;
    CityReader();
    int ctoi(char);
    int stoi(string &);
    void readFromString(string &);
    string findString(string &);
    double findDist(string &);
    void removeSpaces(string &);

};
#endif // CITYREADER_H
