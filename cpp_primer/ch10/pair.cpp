#include <iostream>
#include <vector>
#include <string>
#include <utility>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::pair;

void make_pair_vector_v1(vector<pair<string, int> >& pairVec)
{
    string str;
    int i;

    while(cin >> str >> i)
    {
        pair<string, int> pairElement(str, i);
        pairVec.push_back(pairElement);
    }
}

void make_pair_vector_v2(vector<pair<string, int> >& pairVec)
{
    string str;
    int i;
    while(cin >> str >> i)
    {
        pair<string, int> pairElement;
        pairElement.first = str;
        pairElement.second = i;
        pairVec.push_back(pairElement);
    }
}

void make_pair_vector_v3(vector<pair<string, int> >& pairVec)
{
    string str;
    int i;

    while(cin >> str >> i)
    {
        pair<string, int> pairElement = std::make_pair(str, i);
        pairVec.push_back(pairElement);
    }
}

int main()
{
    vector<pair<string, int> > pairVec;

//    make_pair_vector_v1(pairVec);
//    make_pair_vector_v2(pairVec);
    make_pair_vector_v3(pairVec);

    cout << "pairVec size: " << pairVec.size() << endl;

    return 0;
}
