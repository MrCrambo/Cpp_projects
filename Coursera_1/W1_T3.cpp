#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // find the maximum common subtractor of two numbers
    //
    // used Euclidian algorithm
    
    int a, b;
    cin >> a >> b;
    while (max(a, b) % min(a, b) != 0)
    {
        if (a > b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        } 
    }
    cout << min(a, b);

    return 0;
}