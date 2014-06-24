#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int num;
    std::vector<int> vec;

    while (cin >> num)
    {
        vec.push_back(num);
    }
    
    std::vector<int>::iterator itr;
    for (itr = vec.begin(); itr + 1 < vec.end(); itr+=2)
    {
        cout << *itr + *(itr + 1) << endl;
    }

    if (vec.size() % 2 > 0)
        cout << *itr <<" (last element, not calculated)" << endl;

    return 0;
}
