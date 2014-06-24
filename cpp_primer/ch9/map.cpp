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
    if (argc != 3)
    {
        cout << "Usage: " << argv[0] << " trans_file text_input_file" << endl;
        return -1;
    }

    ifstream map_file;
    if (!open_file_in(map_file, argv[1]))
    {
        cout << "can not open transformation file " << argv[1] << endl;
        return -2;
    }

    map<string, string> trans_map;
    string key, value;
    while (map_file >> key >> value)
        trans_map.insert(make_pair(key, value));

    ifstream input;
    if (!open_file_in(input, argv[2]))
    {
        cout << "can not open input file " << argv[2] << endl;
        return -2;
    }

    string line;
    while (getline(input, line))
    {
        istringstream stream(line);
        string word;
        bool firstword = true;
        while (stream >> word)
        {
            map<string, string>::iterator map_itr =
                                    trans_map.find(word);
            if (map_itr != trans_map.end())
                word = map_itr->second;

            if (firstword)
                firstword = false;
            else
                cout << " ";
            cout << word;
        }
        cout << endl;
    }

    return 0;
}
