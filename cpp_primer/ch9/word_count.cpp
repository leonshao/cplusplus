#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::set;
using std::string;
using std::ifstream;
using std::istringstream;
using std::make_pair;
using std::getline;

ifstream& open_file_in(ifstream& in, string file)
{
    in.close();
    in.clear();

    in.open(file.c_str(), ifstream::binary);
    return in;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " input_file" << endl;
        return -1;
    }

    ifstream input;
    if (!open_file_in(input, argv[1]))
    {
        cout << "can not open input file " << argv[1] << endl;
        return -2;
    }

    map<string, int> word_map;
    string word;
    while (input >> word)
        ++word_map[word];

    map<string, int>::iterator map_itr = word_map.begin();
    while (map_itr != word_map.end())
    {
        cout << map_itr->first << " " << map_itr->second << endl;
        ++map_itr;
    }
}
