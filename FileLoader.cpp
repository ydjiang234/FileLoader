#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "FileLoader.h"

using std::array;
using std::string;
using std::vector;
using std::stringstream;

FileLoader::FileLoader() {}
FileLoader::~FileLoader() {}


stringstream FileLoader::FileToString(char *path)
{
    std::ifstream t(path);
    stringstream buffer;
    buffer << t.rdbuf();
    return buffer;
}

vector<vector<string>> FileLoader::FileToStringArray(char *path, char delim, int buffersize)
{
    vector<vector<string>> out;
    stringstream buffer = FileToString(path);
    //Initial line
    char *temp_line = new char[buffersize];

    while (buffer.getline(temp_line, buffersize))
    {
        vector<string> temp_vector;
        string temp_line_str = string(temp_line);
        if (delim != ' ')
            std::replace(temp_line_str.begin(), temp_line_str.end(), delim, ' ');
        stringstream ss(temp_line_str);
        string temp;
        while (ss >> temp)
            temp_vector.push_back(temp);
        out.push_back(temp_vector);
    }
    return out;
}

vector<vector<double>> FileLoader::FileToDoubleArray(char *path, char delim, int buffersize)
{
    vector<vector<string>> input = FileToStringArray(path, delim, buffersize);
    vector<vector<double>> out;
    for (int i=0; i<input.size(); i++)
    {
        vector<double> temp_vector;
        for (int j=0; j<input[i].size(); j++)
        {
            temp_vector.push_back(StrToDouble(input[i][j]));
        }
        out.push_back(temp_vector);
    }
    return out;
}

vector<vector<long>> FileLoader::FileToLongArray(char *path, char delim, int buffersize)
{
    vector<vector<string>> input = FileToStringArray(path, delim, buffersize);
    vector<vector<long>> out;
    for (int i=0; i<input.size(); i++)
    {
        vector<long> temp_vector;
        for (int j=0; j<input[i].size(); j++)
        {
            temp_vector.push_back(StrToLong(input[i][j]));
        }
        out.push_back(temp_vector);
    }
    return out;
}



/*
vector<vector<string>> FileLoader::FileToString(char *path, char delim, int buffersize)
{
    vector<vector<string>> out;
    //Read file
    std::ifstream file;
    file.open(path, std::ifstream::in);
    //Initial line
    char *temp_line = new char[buffersize];
    string temp_line_str;
    //Iterate from line to line
    vector<string> temp_vector;
    while(file.getline(temp_line, buffersize))
    {

        temp_line_str = string(temp_line);
        if (delim != ' ')
            std::replace(temp_line_str.begin(), temp_line_str.end(), delim, ' ');
        stringstream ss(temp_line_str);
        string temp;
        while (ss >> temp)
            temp_vector.push_back(temp);
        out.push_back(temp_vector);
        temp_vector.clear();
    }
    file.close();
    return out;
}
*/

long FileLoader::StrToLong(string input)
{
    long out;

    stringstream ss(input);
    ss >> out;
    return out;
}

double FileLoader::StrToDouble(string input)
{
    double out;
    stringstream ss(input);
    ss >> out;
    return out;
}
