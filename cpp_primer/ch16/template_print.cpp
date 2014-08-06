#include "common_include.h"
#include <sstream>
using std::stringstream;

template <typename T> void print_elements(const T& container)
{
    // size()�ĵ�����Ҫ����������, ��Ϊsize()����static����
    typename T::size_type container_size = container.size();
    typename T::size_type i;
    for(i = 0; i != container_size; ++i)
        cout << container[i] << endl;
}

template <typename T, size_t N> void printValues(const T(&array)[N])
{
    for (size_t i = 0; i != N; ++i)
    {
        cout << array[i] << endl;
    }
}

// ע��T&ǰ����const, ��Ϊiterator�ĸ�ֵ����(operator=)�ββ���const����
template <typename T> void print_elements_itr(T& container)
{
    typename T::iterator itr;
    for(itr = container.begin(); itr != container.end(); ++itr)
        cout << *itr << endl;
}

int main()
{
    vector<int> vecInt;
    int i;
    for(i = 0; i != 10; ++i)
        vecInt.push_back(i);

//    print_elements_itr(vecInt);

    vector<string> vecStr;
    for(i = 0; i != 10; ++i)
    {
        stringstream ss;
        ss << "str" << i;
        vecStr.push_back(ss.str());
    }

//    print_elements(vecStr);

    int arrInt[10];
    for(i = 0; i != 10; ++i)
        arrInt[i] = i;
    printValues(arrInt);

    string arrStr[10];
    for(i = 0; i != 10; ++i)
    {
        stringstream ss;
        ss << "str" << i;
        arrStr[i] = ss.str();
    }
    printValues(arrStr);

    return 0;
}
