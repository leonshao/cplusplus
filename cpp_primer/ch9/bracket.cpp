#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::stack;
using std::stringstream;

int main()
{
    string expr;
    // ��getline��ȡһ����, cin�Ļ�, Ĭ�������ո�ͽض�
    while(std::getline(cin, expr))
    {
        if(expr.find('(') == string::npos)
            continue;

        stack<string> strStack;
        int replace_value = 0;
        for(string::size_type i=0; i < expr.size(); ++i)
        {
            if(expr[i] != ')')  // ��������, ֱ����ջ
            {
                stringstream charString;
                charString << expr[i];
                strStack.push(charString.str());
            }
            else
            {
                // ����������,����֮ǰջ������, ֱ������������
                string exprInBracket;
                while(strStack.top().compare("("))
                {
                    // ע��Ҫ��insert, ������append, ����˳���෴
                    exprInBracket.insert(0, strStack.top());
                    strStack.pop();
                }
                // ע��������ҲҪ����
                strStack.pop();

                // ��#1, #2���滻()����
                stringstream ss;
                ss << '#' << ++replace_value;
                
                strStack.push(ss.str());
                cout << ss.str() << ": (" << exprInBracket << ")" << endl; 
            }
        }
    }
}
