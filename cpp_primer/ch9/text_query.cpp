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

typedef vector<string>::size_type line_no_t;

class TextQuery
{
public:
    void read_file(ifstream& is)
    {
        store_file(is);
        build_map();
    }
    set<line_no_t> run_query(const string& word) const;
    string text_line(line_no_t line_no) const;

    void dump_file();
    void dump_map();
private:
    void store_file(ifstream& is);
    void build_map();

    vector<string> lines_to_text;
    map< string, set<line_no_t> > word_map;
};

void TextQuery::store_file(ifstream& is)
{
    string line;
    lines_to_text.push_back(line);
    while (getline(is, line))
        lines_to_text.push_back(line);
}

void TextQuery::build_map()
{
    if (lines_to_text.size())
    {
        line_no_t line_size = lines_to_text.size();
        for(line_no_t line_no = 1; line_no < line_size; ++line_no)
        {
            istringstream stream(lines_to_text[line_no]);
            string word;
            // 可以直接简化成一句: word_map[word].insert(line_no);
            // 用find反而要写多判断
            while (stream >> word)  
                word_map[word].insert(line_no);
        }
    }
    else
        cout << "empty file!" << endl;
}

set<line_no_t> TextQuery::run_query(const string& word) const
{
    map< string, set<line_no_t> >::const_iterator map_itr = word_map.find(word);
    if (map_itr != word_map.end())
        return map_itr->second;
    else
    {
        set<line_no_t> empty_set;
        return empty_set;
    }
}

string TextQuery::text_line(line_no_t line_no) const
{
    if (line_no < lines_to_text.size())
        return lines_to_text[line_no];
    else
    {
        cout << "line_no out of range!" << endl;
        return "";
    }
}


void TextQuery::dump_file()
{
    vector<string>::iterator itr = lines_to_text.begin();
    while (itr != lines_to_text.end())
    {
        cout << *itr << endl;
        ++itr;
    }
}

void TextQuery::dump_map()
{
    map< string, set<line_no_t> >::iterator map_itr = word_map.begin();
    while (map_itr != word_map.end())
    {
        cout << map_itr->first << ":";
        set<line_no_t>::iterator set_itr = map_itr->second.begin();
        while (set_itr != map_itr->second.end())
        {
            cout << " " << *set_itr;
            ++set_itr;
        }
        cout << endl;

        ++map_itr;
    }
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        cout << "Usage: " << argv[0] << " input_file query_word" << endl;
        return -1;
    }

    ifstream input;
    input.open(argv[1]);

    TextQuery oTextQuery;
    oTextQuery.read_file(input);
    set<line_no_t> word_lines = oTextQuery.run_query(argv[2]);

    cout << argv[2] << " occurs " << word_lines.size() << " times" << endl;
    for(set<line_no_t>::iterator set_itr = word_lines.begin();
        set_itr != word_lines.end(); ++set_itr)
        cout << "    (line " << *set_itr << ") " << oTextQuery.text_line(*set_itr) << endl;

    return 0;
}
