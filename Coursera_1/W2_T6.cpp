#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
    map<string, vector<string> > bus_stops; // вектор остановок для каждого автобуса
    map<string, vector<string> > stop_busses; // вектор автобусов для каждой остановки
    int count;
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        string operation;
        cin >> operation;

        if (operation == "ALL_BUSES")
        {
            if (bus_stops.size() == 0)
            {
                cout << "No buses" << endl;
            }
            else
            {
                for (auto bus: bus_stops)
                {
                    cout << "Bus " << bus.first << ":";
                    for (auto stop: bus.second)
                    {
                        cout << " " << stop;
                    }
                    cout << endl;
                }
            }  
        }
        else if (operation == "BUSES_FOR_STOP")
        {
            string stop_name;
            cin >> stop_name;

            if (stop_busses.count(stop_name) == 0)
                cout << "No stop";
            else
                for (auto bus_name: stop_busses[stop_name])
                {
                    cout << bus_name << " ";
                }
            cout << endl;
        }
        else if (operation == "STOPS_FOR_BUS")
        {
            string bus_number;
            cin >> bus_number;

            if (bus_stops.count(bus_number) == 0)
            {
                cout << "No bus" << endl;
            }
            else
            {
                for (auto stop: bus_stops[bus_number])
                {
                    cout << "Stop " << stop << ":";
                    vector<string> bus_names = stop_busses[stop];
                    if (bus_names.size() == 1)
                        cout << " no interchange";
                    else
                        for (auto bus_name: bus_names)
                        {
                            if (bus_name != bus_number)
                                cout << " " << bus_name;
                        }
                    cout << endl;
                }   
            }        
        }
        else
        {
            string bus_number, stop_name;
            int stop_counts;

            cin >> bus_number;
            cin >> stop_counts;
            
            for (int i = 0; i < stop_counts; i++)
            {
                cin >> stop_name;
                bus_stops[bus_number].push_back(stop_name);
                stop_busses[stop_name].push_back(bus_number);
            }   
        }
    }
    return 0;
}