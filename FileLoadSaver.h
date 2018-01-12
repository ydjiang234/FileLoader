#ifndef FileLoader_h
#define FileLoader_h
#include <iostream>
#include <vector>
#include <sstream>

using std::string;
using std::vector;
using std::stringstream;

class FileLoader
{
public:
    FileLoader();
    ~FileLoader();
    stringstream FileToString(char *path);
    vector<vector<string>> FileToStringArray(char *path, char delim = ' ', int buffersize=100);
    vector<vector<double>> FileToDoubleArray(char *path, char delim = ' ', int buffersize=100);
    vector<vector<long>> FileToLongArray(char *path, char delim = ' ', int buffersize=100);
private:
    long StrToLong(string input);
    double StrToDouble(string input);
};



#endif
