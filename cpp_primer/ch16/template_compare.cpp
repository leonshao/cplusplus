#include "common_include.h"

template <typename T> int compare(const T& val1, const T& val2)
{
    if(val1 < val2) 
        return -1;
    else if(val1 == val2) 
        return 0;
    else 
        return 1;
}

int main()
{
    int i = 1;
    short si = 0;
    cout << "compare<int>(i, si): " << compare<int>(i, si) << endl;
    cout << "compare<short>(i, si): " << compare<short>(i, si) << endl;

    cout << "compare<string>(str1, str2): " << compare<string>("str1", "str2") << endl;

    return 0;
}
