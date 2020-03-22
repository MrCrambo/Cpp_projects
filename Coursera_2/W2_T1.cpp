#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType 
{
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query 
{
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

ostream& operator << (ostream& os, const vector<string> v) 
{
	for (int i = 0; i + 1 < v.size(); i++) 
    {
		os << v[i] << " ";
	}

	os << v[v.size()-1] ;

	return os;
}

istream& operator >> (istream& is, Query& q) 
{
  	string command, stop_i;
	is >> command;
	int ctr;
	q.stops = {};

	if (command == "NEW_BUS") 
    {
		q.type = QueryType::NewBus;
		is >> q.bus >> ctr;
		for (int i = 0; i < ctr; i++) 
        {
			is >> stop_i;
			q.stops.push_back(stop_i);
		}
	} 
    else if (command ==  "BUSES_FOR_STOP") 
    {
		q.type = QueryType::BusesForStop;
		is >> q.stop;
	} 
    else if (command == "STOPS_FOR_BUS") 
    {
		q.type = QueryType::StopsForBus;
		is >> q.bus;
	} 
    else if (command == "ALL_BUSES")
		q.type = QueryType::AllBuses;
	else
		throw runtime_error ("wrong command");

	return is;
}

struct BusesForStopResponse 
{
    string stop;
	bool exists;
	vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) 
{
    if (r.exists)
		os << r.buses;
	else
		os << "No stop";
	return os;
}

struct StopsForBusResponse 
{
    string bus;
	bool exists;
	vector<string> stop_names;
	map<string, vector<string>> stop_to_buses;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) 
{
    if (r.exists) 
    {
		int ctr = 0;

		for (auto stop : r.stop_names) 
        {
			++ctr;

			os << "Stop " << stop << ": " ;
			if (r.stop_to_buses.at(stop).size() == 1)
				os << "no interchange";
			else 
            {
				for (auto bus : r.stop_to_buses.at(stop)) 
                {
					if (bus != r.bus)
						os << bus << " ";
				}
			}
			if (ctr < r.stop_names.size())
				os << endl;
		}
	} 
    else
		os << "No bus";

	return os;
}

struct AllBusesResponse 
{
    bool exists;
	vector<StopsForBusResponse> buses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) 
{
    if (r.exists) 
    {
		for (auto bus : r.buses) 
        {
			os << "Bus " << bus.bus << ": " << bus.stop_names << endl;
		}
	} 
    else
		os << "No buses";

    return os;
}

class BusManager 
{
    public:
        void AddBus(const string& bus, const vector<string>& stops) 
        {
            for (auto i : stops) {
                buses_map[bus].push_back(i);
                stops_map[i].push_back(bus);
            }
        }

        BusesForStopResponse GetBusesForStop(const string& stop) const 
        {
            BusesForStopResponse res;
            res.stop = stop;
            if (stops_map.count(stop) == 0) 
            {
                res.exists = false;
                return res;
            } 
            else 
            {
                res.exists = true;
                res.buses = {};
                for (auto i : stops_map.at(stop)) 
                {
                    res.buses.push_back(i);
                }
            }

            return res;
        }

        StopsForBusResponse GetStopsForBus(const string& bus) const 
        {
            StopsForBusResponse res;
            res.bus = bus;
            if (buses_map.count(bus) == 0) 
            {
                res.exists = false;
                return res;
            } 
            else 
            {
                res.exists = true;
                res.stop_names = buses_map.at(bus);
                for (string stop : res.stop_names) 
                {
                    res.stop_to_buses[stop] = stops_map.at(stop);
                }
            }

            return res;
        }

        AllBusesResponse GetAllBuses() const 
        {
            AllBusesResponse res;
            if (buses_map.empty()) {
                res.exists = false;
                return res;
            } else {
                res.exists = true;
                for (auto bus : buses_map) {
                    res.buses.push_back(GetStopsForBus(bus.first));
                }
            }
            return res;
        }

    private:
        map<string, vector<string>> buses_map, stops_map;
};

int main() 
{
    int query_count;
    Query q;

    cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) 
    {
        cin >> q;
        switch (q.type) 
        {
            case QueryType::NewBus:
                bm.AddBus(q.bus, q.stops);
                break;
            case QueryType::BusesForStop:
                cout << bm.GetBusesForStop(q.stop) << endl;
                break;
            case QueryType::StopsForBus:
                cout << bm.GetStopsForBus(q.bus) << endl;
                break;
            case QueryType::AllBuses:
                cout << bm.GetAllBuses() << endl;
                break;
        }
    }

    return 0;
}