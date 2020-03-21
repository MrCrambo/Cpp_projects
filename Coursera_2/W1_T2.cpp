#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // calculating the weigths of all the blocks (task for types of int)
    uint n, r;
    uint64_t w, h, d;
    uint64_t sum = 0;
    cin >> n >> r;
    for (size_t i = 0; i < n; i++)
    {
        cin >> w >> h >> d;
        sum += w * h * d * r; //  w, h and d should be casted to uint64_t because othervise multipliing will be casted to int
    }
    
    cout << sum;

    return 0;
}