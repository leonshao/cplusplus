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

    int vec_size = vec.size();
    int *pa = new int[vec_size];
    for (int i = 0; i < vec_size; i++)
    {
        pa[i] = vec[i];
    }

    for (int *p = pa; p != pa + vec_size; p++)
        cout << *p << " ";

    cout << endl;

    delete [] pa;

    return 0;
}
