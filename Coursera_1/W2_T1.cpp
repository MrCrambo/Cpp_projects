#include <iostream>

using namespace std;

int Factorial(int arg)
{
    int result = 1;
    if (arg > 0)
    {
        for (int i = 1; i <= arg; i++)
            result *= i;
    }

    return result;
}

int main()
{
    int a;
    cin >> a;
    cout << Factorial(a); 
    return 0;
}