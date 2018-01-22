#ifndef FileLoadSaver_h
#define FileLoadSaver_h
#include <iostream>
#include <vector>
#include <sstream>

using std::string;
using std::vector;
using std::stringstream;

class FileLoadSaver
{
public:
    FileLoadSaver();
    ~FileLoadSaver();
    stringstream FileToString(string path);
    vector<vector<string>> FileToStringArray(string path, char delim = ' ');
    vector<vector<double>> FileToDoubleArray(string path, char delim = ' ');
    vector<vector<long>> FileToLongArray(string path, char delim = ' ');
    void DoubleArrayToFile(vector<vector<double>> input, string path, char delim = ' ');
    void LongArrayToFile(vector<vector<long>> input, string path, char delim = ' ');

private:
    long StrToLong(string input);
    double StrToDouble(string input);
    void SStoFile(string path, stringstream& ss);
};



#endif
