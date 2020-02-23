#include <set>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<set<string>, int> stops_map;
    int count;
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        int stops_count;
        cin >> stops_count;
        set<string> stops;

        for (int i = 0; i < stops_count; i++)
        {
            string stop;
            cin >> stop;
            stops.insert(stop);
        }

        if (stops_map.count(stops) == 0)
        {
            int size = stops_map.size() + 1;
            stops_map[stops] = size;
            cout << "New bus " <<  size << endl;
        }
        else
        {
            cout << "Already exists for " << stops_map[stops] << endl;
        }
    }
    
    return 0;
}