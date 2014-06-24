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
    // 用getline读取一整行, cin的话, 默认遇到空格就截断
    while(std::getline(cin, expr))
    {
        if(expr.find('(') == string::npos)
            continue;

        stack<string> strStack;
        int replace_value = 0;
        for(string::size_type i=0; i < expr.size(); ++i)
        {
            if(expr[i] != ')')  // 非右括号, 直接入栈
            {
                stringstream charString;
                charString << expr[i];
                strStack.push(charString.str());
            }
            else
            {
                // 遇到右括号,弹出之前栈的内容, 直到遇到左括号
                string exprInBracket;
                while(strStack.top().compare("("))
                {
                    // 注意要用insert, 而不是append, 否则顺序相反
                    exprInBracket.insert(0, strStack.top());
                    strStack.pop();
                }
                // 注意左括号也要弹出
                strStack.pop();

                // 用#1, #2等替换()内容
                stringstream ss;
                ss << '#' << ++replace_value;
                
                strStack.push(ss.str());
                cout << ss.str() << ": (" << exprInBracket << ")" << endl; 
            }
        }
    }
}
