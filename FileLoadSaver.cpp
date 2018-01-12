#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "FileLoadSaver.h"

using std::string;
using std::vector;
using std::stringstream;

FileLoadSaver::FileLoadSaver() {}
FileLoadSaver::~FileLoadSaver() {}


stringstream FileLoadSaver::FileToString(string path)
{
    //char *chr = strdup(path.c_str());
    std::ifstream t(path, std::ifstream::in);
    stringstream buffer;
    buffer << t.rdbuf();
    return buffer;
}

vector<vector<string>> FileLoadSaver::FileToStringArray(string path, char delim, int buffersize)
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

vector<vector<double>> FileLoadSaver::FileToDoubleArray(string path, char delim, int buffersize)
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

vector<vector<long>> FileLoadSaver::FileToLongArray(string path, char delim, int buffersize)
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

long FileLoadSaver::StrToLong(string input)
{
    long out;

    stringstream ss(input);
    ss >> out;
    return out;
}

double FileLoadSaver::StrToDouble(string input)
{
    double out;
    stringstream ss(input);
    ss >> out;
    return out;
}

void FileLoadSaver::SStoFile(string path, stringstream& ss)
{
    //char *chr = strdup(path.c_str());
    std::ofstream t(path, std::ifstream::out);
    t<<ss.str();
    t.close();
}

void FileLoadSaver::DoubleArrayToFile(vector<vector<double>> input, string path, char delim)
{
    int m = input.size();
    int n = input[0].size();
    stringstream out;
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            out<<' ';
            out<<input[i][j];
            if (j!=n-1)
                out<<delim;
        }
        if (i!=m-1)
            out<<'\n';
    }
    this->SStoFile(path, out);
}

void FileLoadSaver::LongArrayToFile(vector<vector<long>> input, string path, char delim)
{
    int m = input.size();
    int n = input[0].size();
    stringstream out;
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            out<<' ';
            out<<input[i][j];
            if (j!=n-1)
                out<<delim;
        }
        out<<'\n';
    }
    this->SStoFile(path, out);
}
