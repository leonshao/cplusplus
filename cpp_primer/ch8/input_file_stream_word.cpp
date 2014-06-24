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
    string ifile = "input_file_stream_word.cpp";
    string word;
    std::ifstream input;
    input.open(ifile.c_str());  // file is opened
    vector<string> vec;

    if(!input)
    {
        cout << "file " << ifile << " not found" << endl;
        return 1;
    }

    while(input >> word)
    {
        vec.push_back(word);
    }

    vector<string>::iterator itr;
    for(itr = vec.begin(); itr != vec.end(); ++itr)
    {
        cout << *itr << endl;
    }

    input.close();
    return 0;
}
