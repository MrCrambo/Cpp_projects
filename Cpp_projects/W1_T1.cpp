#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[]) {
    
    // enter three numbers and solve Ax^2 + Bx + C
    double a, b, c;
    cin >> a >> b >> c;
    
    double d = sqrt(b * b - 4 * a * c);
    
    if (a == 0 && b == 0)
        return 0;
    else if (a == 0 && b != 0)
        cout << -c / b;
    else if (d == 0)
        cout << -b / (2 * a);
    else if(d > 0)
        cout << (-b + d) / (2 * a)  << " " << (-b - d) / (2 * a);
    
    return 0;
}

