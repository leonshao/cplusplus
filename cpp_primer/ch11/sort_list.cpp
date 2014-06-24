#include <algorithm>
#include <list>
#include <iostream>
#include <string>
using std::list;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::unique;
using std::stable_sort;
using std::count_if;

void print_words(list<string> &words)
{
    list<string>::iterator itr;
    for (itr = words.begin(); itr != words.end(); ++itr)
        cout << *itr << " ";
    cout << endl;
}

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

bool GT6(const string &s)
{
    return s.size() >= 6;
}

int main()
{
    list<string> words;
    string next_word;

    while (cin >> next_word)
        words.push_back(next_word);

    words.sort();
    print_words(words);

    words.unique();
    print_words(words);

    list<string>::size_type wc = count_if(words.begin(), words.end(), GT6);
    cout << wc << " words 6 characters or longer" << endl;
    return 0;
}
