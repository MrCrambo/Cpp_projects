#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // calculating the average temperature (task for types of int)
    vector<int> temperatures;
    int64_t days_count = 0, avg = 0, avg_count = 0;
    string expr = "";
    cin >> days_count;
    for (int i = 0; i < days_count; i++)
    {
        int temp;
        cin >> temp;
        temperatures.push_back(temp);
        avg += temp;
    }
    avg /= days_count;

    for (int i = 0; i < days_count; i++)
    {
        if (temperatures[i] > avg)
            avg_count++;
    }
    cout << avg_count << endl;

    for (int i = 0; i < days_count; i++)
    {
        if (temperatures[i] > avg)
            cout << i << " ";
    }

    return 0;
}