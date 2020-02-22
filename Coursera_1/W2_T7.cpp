#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int count;
    cin >> count;
    map<vector<string>, int > routes;

    for (int i = 0; i < count; i++)
    {
        int stop_count;
        vector<string> stops;
        cin >> stop_count;

        for (int j = 0; j < stop_count; j++)
        {
            string stop;
            cin >> stop;
            stops.push_back(stop);
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