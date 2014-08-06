#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;

template <typename T> int compare(const T& obj1, const T& obj2)
{
    if(obj1 < obj2) return -1;
    else if (obj1 == obj1) return 0;
    else return 1;
}

int main()
{
    cout << "compare(\"hello\", \"hello\"): " << compare("hello", "hello") << endl;
    string str1 = "hello";
    string str2 = "hello";
    cout << "compare(str1, str2): " << compare(str1, str2) << endl;

    double d1 = 3.14;
    double d2 = 3.104;
    cout << "compare(d1, d2): " << compare(d1, d2) << endl;

//    int i1 = 0;
//    int i2 = 1;
//    cout << "compare(i1, i2): " << compare(i1, i2) << endl;

    return 0;
}
