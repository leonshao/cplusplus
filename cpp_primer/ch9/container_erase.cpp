#include <iostream>
#include <vector>
#include <list>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::list;

int main()
{
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };

    // copy ia to vector and list
    vector<int> iVec;
    list<int> iList;
    int a_size = sizeof(ia) / sizeof(int);
    for (int i = 0; i < a_size; ++i)
    {
        iVec.push_back(ia[i]);
        iList.push_back(ia[i]);
        cout << iVec[i] << ", ";
    }
    cout << endl;

    // erase odd for list, even for vector
    vector<int>::iterator itrVec;
    list<int>::iterator itrList;

    // 用一个循环删
    itrVec = iVec.begin();
    itrList = iList.begin();
    while(itrVec != iVec.end() || itrList != iList.end())
    {
        while( (itrVec != iVec.end()) && ((*itrVec % 2) ==0) )
        {
            itrVec = iVec.erase(itrVec);
            if(itrList != iList.end())
                ++itrList;
        }
        while( (itrList != iList.end()) && (*itrVec % 2) )
        {
            itrList = iList.erase(itrList);
            if(itrVec != iVec.end())
                ++itrVec;
        }
    }

    /*
    // 用两个循环删
    for (itrList = iList.begin(); itrList != iList.end(); ++itrList)
    {
        // .erase()返回指向下一元素的迭代器, 
        // 所以要用while删除连续的符合条件的元素
        while(*itrList % 2)
            itrList = iList.erase(itrList);
    }

    for (itrVec = iVec.begin(); itrVec != iVec.end(); ++itrVec)
    {
        while((*itrVec % 2) == 0)
            itrVec = iVec.erase(itrVec);
    }
    */

    for (itrList = iList.begin(); itrList != iList.end(); ++itrList)
        cout << *itrList << ", ";
    cout << endl;

    for (itrVec = iVec.begin(); itrVec != iVec.end(); ++itrVec)
        cout << *itrVec << ", ";
    cout << endl;
}

