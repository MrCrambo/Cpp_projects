#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int count;
    cin >> count;
    vector<int> numbers(count);
    for (auto& n: numbers)
    {
        cin >> n;
    }
    
    sort(begin(numbers), end(numbers), [](int i, int j){return abs(i) < abs(j);}); //  sorting with lambda for abs numbers
    
    for (const auto& n: numbers)
    {
        cout << n << " ";
    }
    

    return 0;
}