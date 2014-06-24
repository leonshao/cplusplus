#include <iostream>
#include <vector>
#include <string>
#include <stack>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::stack;

int main()
{
    const stack<int>::size_type stack_size = 10;
    stack<int> intStack;
    int ix = 0;
    cout << "push: ";
    while(intStack.size() != stack_size)
    {
        intStack.push(ix++);
        cout << intStack.top() << ", ";
    }
    cout << endl;

    int error_cnt = 0;
    cout << "pop: ";
    while(!intStack.empty())
    {
        int value = intStack.top();

        if (value != --ix)
        {
            cout << "oops! expected " << ix 
                 << " received " << value << endl;
            ++error_cnt;
        }
        else
            cout << value << ", ";

        intStack.pop();
    }
    cout << endl;

    cout << "Our program ran with "
         << error_cnt << " errors!" << endl;
}
