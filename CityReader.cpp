#include "CityReader.h"
#include <fstream>
#include <iostream>
using namespace std;
CityReader::CityReader()
{
    ifstream iFile;
    iFile.open("CityMap.txt");
    if(iFile.is_open())
    {
        string tmpName;
        string dumpLine;
        while( iFile >> tmpName)
        {
            namesOfJunctions.push(tmpName);
            getline(iFile, dumpLine);
            removeSpaces(dumpLine);
            //cout << "line is" << dumpLine << endl;
            if(!dumpLine.empty())
            {
                dumpLine.erase(0,1);
                readFromString(dumpLine);
            }
        }
    }
}
int CityReader::ctoi(char c)
{
    switch(c)
    {
    case '0' :
        return 0;
    case '1' :
        return 1;
    case '2' :
        return 2;
    case '3' :
        return 3;
    case '4' :
        return 4;
    case '5' :
        return 5;
    case '6' :
        return 6;
    case '7' :
        return 7;
    case '8' :
        return 8;
    case '9' :
        return 9;
    }
}
int CityReader::stoi(string & s)
{
    int tmp = 0;
    for(int i = 0 ; i < s.length() ; i ++)
    {
        if(s.at(i) >= '0' && s.at(i) <= '9')
        {
            tmp*=10;
            tmp+=ctoi(s.at(i));
        }
    }
    return tmp;
}
void CityReader::readFromString(string & s)
{
    pair<string , double> tmpPair;
    queue< pair < string , double > > tmpNameOfToJunctions;
    while(!s.empty())
    {
        tmpPair.first = findString(s);
        tmpPair.second = findDist(s);
        tmpNameOfToJunctions.push(tmpPair);
    }
    namesOfToJunctions.push(tmpNameOfToJunctions);
}
string CityReader::findString(string & s)
{
    string tmp;
    int i = 0;
    while(s.at(i) != ' ')
        i++;
    tmp.append(s , 0 , i);
    s.erase(0 , i+1);
    return tmp;
}
double CityReader::findDist(string & s)
{
    string tmp;
    int i = 0;
    while(i != (s.length()) && s.at(i) != ' ')
        i++;
    tmp.append(s , 0 , i);
    s.erase(0,i);
    if(!s.empty())
        s.erase(0,1);
    return stoi(tmp);
}
void CityReader::removeSpaces(string & tmp)
{
    if(tmp.at(tmp.size() - 1) == ' ')
    {
        tmp.erase(tmp.size() - 1 , 1);
        removeSpaces(tmp);
    }
}


