#include <iostream>
#include <string>

using namespace std;

string reverseStr(string text)
{
    string new_text = "";
    for (int i = text.size() - 1; i > -1; i--)
    {
        new_text += text[i];
    }
    
    return new_text;
}

int main()
{
    // casting decimal number to binary number (without using vectors and reversed from c++ 11)
    int number;
    string result;
    cin >> number;
    while (number != 1)
    {
        result += to_string(number % 2);
        number /= 2; 
    }

    cout << 1 << reverseStr(result);

    return 0;
}