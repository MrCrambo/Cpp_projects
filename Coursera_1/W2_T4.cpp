#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // task with commands and vector modifiying
    int n;
    cin >> n;
    vector<bool> persons;
    for (size_t i = 0; i < n; i++)
    {
        string operation;
        cin >> operation;
        if (operation == "COME")
        {
            int count;
            cin >> count;
            persons.resize(persons.size() + count, false);
        }
        else if (operation == "WORRY")
        {
            int pos;
            cin >> pos;
            persons[pos] = true;
        }
        else if(operation == "QUIET")
        {
            int pos;
            cin >> pos;
            persons[pos] = false;
        }
        else
            cout << count(persons.begin(), persons.end(), true) << endl;
    }
    
    return 0;
}