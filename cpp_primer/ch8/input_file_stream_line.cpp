#include <iostream>
#include <fstream>  // ifstream, ofstream, fstream
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    string ifile = "input_file_stream_line.cpp";
    string line;
    std::ifstream input(ifile.c_str());
    vector<string> vec;

    if(!input)
    {
        cout << "can not open file " << ifile << endl;
        return 1;
    }

    while(std::getline(input, line))
    {
        vec.push_back(line);
    }

    vector<string>::iterator itr;
    for(itr = vec.begin(); itr != vec.end(); ++itr)
    {
        cout << *itr << endl;
    }

    input.close();
    return 0;
}
