#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
    deque<string> expression;
    int n, operand;
    string operation;
    cin >> operand >> n;
    expression.push_back(to_string(operand));
    while(n > 0)
    {
        expression.push_front("(");
        expression.emplace_back(")");
        cin >> operation >> operand;
        expression.push_back(" " + operation + " ");
        expression.push_back(to_string(operand));
        --n;
    }

    for(auto elem : expression)
    {
        cout << elem;
    }

    return 0;
}