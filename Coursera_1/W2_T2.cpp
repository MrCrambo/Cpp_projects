#include <iostream>
#include <string>

using namespace std;

bool IsPalindrom(string text)
{
    // check if the entered text is palindrom

    int len = text.size();
    if (len == 0)
        return true;
    
    for (int i = 0; i < len / 2; i++)
    {
        if (text[i] != text[len - i - 1])
            return false;
    }
    
    return true;
}

int main()
{
    string text = "";
    cin >> text;
    cout << IsPalindrom(text);

    return 0;
}