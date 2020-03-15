#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    ifstream input("input.txt");
    if (input)
    {
        int n, m, a;
        input >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m - 1; j++)
            {
                input >> a;
                input.ignore(1);
                cout << setw(10) << a << " ";
            }
            input >> a;
            cout << setw(10) << a;
            if (n - 1 != i)
                cout << endl;
        }
    }

    return 0;
}