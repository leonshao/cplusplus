#include <string>
using std::string;

class Person
{
public:
    Person(string name, string addr): name(name),
    address(addr)
    {
    }

    string getName() const
    {
        return name;
    }

    string getAddress() const
    {
        return address;
    }

private:
    string name;
    string address;
};
