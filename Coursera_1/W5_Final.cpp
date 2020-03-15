#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <vector>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

class Date 
{
    public:
        Date();
        Date(vector<int> date) 
        {
            year = date[0];
            month = date[1];
            day = date[2];
        }

        int GetYear() const 
        {
            return year;
        }

        int GetMonth() const 
        {
            return month;
        }

        int GetDay() const 
        {
            return day;
        }

    private:
        int year = 0;
        int month = 0;
        int day = 0;
};

ostream& operator<<(ostream& output, const Date& date) 
{
    cout << setw(4) << setfill('0') << date.GetYear() << "-" << setw(2) << date.GetMonth() << "-" << setw(2) << date.GetDay();
    return output;
}

void PrintDate(const Date& date, const set<string>& events) 
{
    for (const auto& e : events) 
    {
        cout << date << " " << e << endl;
    }
}

bool operator<(const Date& lhs, const Date& rhs) 
{
    if (lhs.GetYear() != rhs.GetYear())
        return lhs.GetYear() < rhs.GetYear();
    else if (lhs.GetMonth() != rhs.GetMonth())
        return lhs.GetMonth() < rhs.GetMonth();
    else
        return lhs.GetDay() < rhs.GetDay();
}

class Database 
{
    public:
        void AddEvent(const Date& date, const string& event) 
        {
            if (data.count(date) > 0) 
            {
                bool event_exists = false;
                for (const auto& d : data[date]) 
                {
                    if (d == event) 
                    { 
                        event_exists = true;
                        break;
                    }
                }
                if (!event_exists)
                    data[date].insert(event);
            } 
            else
                data[date].insert(event);
        }

        bool DeleteEvent(const Date& date, const string& event) 
        {
            if (data.count(date) > 0) 
            {
                for (auto& d : data[date]) 
                {
                    if (d == event) 
                    { 
                        if (data[date].size() > 1) 
                            data[date].erase(d);
                        else
                            data.erase(date);
                        return true;
                    }
                }
            }
            return false;
        }

        int  DeleteDate(const Date& date) 
        {
            int events_at_date = 0;
            if (data.count(date) > 0) 
            {
                events_at_date = data[date].size();
                data.erase(date);
            }
            return events_at_date;
        }

        void Find(const Date& date) const 
        {
            if (data.count(date) > 0) 
            {
                set<string> events = data.at(date);
                for (const auto& e : events) 
                {
                    cout << e << endl;
                }
            }
        }
    
        void Print() const 
        {
            for (const auto& d : data) 
            {
                PrintDate(d.first, d.second);
            }
        }

    private:
        map<Date, set<string>> data;
};

vector<int> ParseDate(istream& input) 
{
    if (input) 
    {
        string input_date;
        getline(input, input_date, ' ');

        stringstream user_date(input_date);

        int y, m, d;
        char def1, def2;
        try {
            user_date >> y >> def1 >> m >> def2 >> d;
            if (!user_date)
                throw runtime_error(input_date);
            else if (def1 != '-' || def2 != '-')
                throw runtime_error(input_date); 
            else if (user_date.peek() != EOF)
                throw runtime_error(input_date); 
            else 
            {
                if (m > 12 || m < 1)
                    throw invalid_argument("Month value is invalid: " + to_string(m));
                else if (d > 31 || d < 1)
                    throw invalid_argument("Day value is invalid: " + to_string(d));
                else
                    return {y, m, d};             
            }
        } 
        catch (const runtime_error& ex) 
        {
            cout << "Wrong date format: " << ex.what() << endl;
        } 
        catch (const invalid_argument& arg) 
        {
            cout << arg.what() << endl;
        }
    }
    return {0, 0, 0};
}

int main() {
    Database db;
        
    string command;
    while (getline(cin, command)) {
        stringstream user_input(command);
        string task;

        user_input >> task;
        user_input.ignore(1);
        if (task == "Add") 
        {
            Date date = ParseDate(user_input);            
            if (date.GetMonth() != 0) 
            {
                string event;
                getline(user_input, event);
                db.AddEvent(date, event);
            } else
                return 0;
        } 
        else if (task == "Del") 
        {
            Date date = ParseDate(user_input);
            if (date.GetMonth() != 0) {
                if (user_input.peek() != EOF) 
                {
                    string event;
                    getline(user_input, event);
                    if (db.DeleteEvent(date, event))
                        cout << "Deleted successfully" << endl;
                    else
                        cout << "Event not found" << endl;
                } 
                else 
                {
                    int deleted_events_count = db.DeleteDate(date);
                    cout << "Deleted " << deleted_events_count << " events" << endl;
                }
            } 
            else
                return 0;
        } 
        else if (task == "Find") 
        {
            // Date
            Date date = ParseDate(user_input);
            if (date.GetMonth() != 0)
                db.Find(date);
            else
                return 0;
        } 
        else if (task == "Print")
            db.Print();
        else if (!task.empty())
        {
            cout << "Unknown command: " << task << endl;
            return 0;
        }
    }

    return 0;
}