#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    // add new routes and print already exist routes id

    int count;
    cin >> count;
    map<vector<string>, int > routes;

    for (int i = 0; i < count; i++)
    {
        int stop_count;
        vector<string> stops(stop_count);
        cin >> stop_count;

        for (string& stop : stops) 
        {
            cin >> stop;
        }

        if (routes.count(stops) == 0)
        {
            int size = routes.size() + 1;
            routes[stops] = size;
            cout << "New bus " <<  size << endl;
        }
        else
        {
            cout << "Already exists for " << routes[stops] << endl;
        } 
    }
    return 0;
}