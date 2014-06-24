#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::istringstream;

istringstream& print_sstream(istringstream& input)
{
    cout << input.str() << endl;
    input.clear();
    return input;
}

int main()
{
    istringstream input("hello world");

    print_sstream(input);

    return 0;
}
