#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::stringstream;

int main()
{
    string line1 = "We were her pride of 10 she named us:";
    string line2 = "Benjamin, Phoenix, the Prodigal";
    string line3 = "and perspicacious pacific Suzanne";

    string sentence = line1 + ' ' + line2 + ' ' + line3;

    vector<string> shortWords;
    vector<string> longWords;

    stringstream ss(sentence);

    string word;
    string::size_type shortLen = 0;
    string::size_type longLen = 0;
    while (ss >> word)
    {
        string::size_type pos = 0;
        // 去掉单词中的标点符号
        while((pos = word.find_first_of(":,", pos)) != string::npos)
        {
            word.replace(pos, 1, "");
            ++pos;
        }

        string::size_type wordSize = word.size();
        if(shortLen < wordSize && wordSize < longLen)
            continue;

        if(!shortLen)
        {
            shortLen = wordSize;
            shortWords.push_back(word);
        }
        else if(wordSize < shortLen)
        {
            shortLen = wordSize;
            shortWords.clear();
            shortWords.push_back(word);
            continue;
        }
        else if(wordSize == shortLen)
            shortWords.push_back(word);

        if(!longLen)
        {
            longLen = wordSize;
            longWords.push_back(word);
        }
        else if(wordSize > longLen)
        {
            longLen = wordSize;
            longWords.clear();
            longWords.push_back(word);
        }
        else if(wordSize == longLen)
            longWords.push_back(word);
    }

    vector<string>::iterator itr;
    cout << "short words: ";
    for(itr = shortWords.begin(); itr != shortWords.end(); ++itr)
        cout << *itr << ", ";
    cout << endl;

    cout << "long words: ";
    for(itr = longWords.begin(); itr != longWords.end(); ++itr)
        cout << *itr << ", ";
    cout << endl;
}
