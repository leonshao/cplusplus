#include <iostream>
#include <fstream>  // ifstream, ofstream, fstream
#include <sstream>  // istringstream
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::istringstream;

int main()
{
    string file = "input_file_stream_line2.cpp";
    ifstream input(file.c_str());

    if(!input)
    {
        cout << "can not open file " << file << endl;
        return -1;
    }

    vector<string> vec;
    string line;
    while(std::getline(input, line))
        vec.push_back(line);

    vector<string>::iterator itr;
    for(itr=vec.begin(); itr!=vec.end(); ++itr)
    {
        istringstream line_stream(*itr);
        string word;
        while(line_stream >> word)
            cout << word << endl;
    }
    return 0;
}
