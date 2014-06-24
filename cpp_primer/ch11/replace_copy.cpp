#include <algorithm>
#include <iterator>
#include <vector>
#include <list>
#include <iostream>
using std::vector;
using std::list;
using std::cout;
using std::endl;
using std::replace_copy;
using std::find;
using std::back_inserter;
using std::front_inserter;
using std::inserter;

void print_vector(vector<int> &iVec)
{
    vector<int>::iterator itr;
    for (itr = iVec.begin(); itr != iVec.end(); ++itr)
        cout << *itr << " ";
    cout << endl;
}

void print_list(list<int> &iList)
{
    list<int>::iterator itr;
    for (itr = iList.begin(); itr != iList.end(); ++itr)
        cout << *itr << " ";
    cout << endl;
}

int main()
{
    vector<int> iVec;
    for (int i = 0; i < 10; ++i)
        iVec.push_back(i);

    print_vector(iVec);

//    vector<int>::iterator itr = find();
    cout << "inserter: ";
    vector<int> vecInserter;
    replace_copy(iVec.begin(), iVec.end(), inserter(vecInserter, vecInserter.begin()), 9, 10);
    print_vector(vecInserter);

    cout << "back_inserter: ";
    vector<int> vecBack;
    replace_copy(iVec.begin(), iVec.end(), back_inserter(vecBack), 9, 10);
    print_vector(vecBack);

    cout << "front_inserter: ";
    list<int> listFront;
    replace_copy(iVec.begin(), iVec.end(), front_inserter(listFront), 9, 10);
    print_list(listFront);
}
