#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

string greet(string form, string lastName, string title,
             string::size_type pos, int length)
{
    string name("Daisy");
    form.replace(form.find(name), name.size(), lastName);

    string t_rep("Ms");
    form.replace(form.find(t_rep), t_rep.size(), title.substr(pos, length));

    return form;
}

int main()
{
    string generic1("Dear Ms Daisy:");
    string generic2("MrsMsMissPeople");

    string lastName("AnnaP");
    string salute = greet(generic1, lastName, generic2, 5, 4);

    cout << salute << endl;

    return 0;
}

