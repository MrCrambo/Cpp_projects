#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) 
    {
        if (names.count(year) == 0)
            names[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) 
    {
        if (surnames.count(year) == 0)
            surnames[year] = last_name;
    }
    string GetFullName(int year) 
    {
        string full_name;
        int y1 = GetPreviousChangeYear(names, year);
        int y2 = GetPreviousChangeYear(surnames, year);
        if (y1 == 0 && y2 == 0)
            full_name = "Incognito";
        else if(y1 != 1 && y2 == 0)
            full_name = names[y1] + " with unknown last name";
        else if(y1 == 0 && y2 != 0)
            full_name = surnames[y2] + " with unknown first name";
        else
            full_name = names[y1] + " " + surnames[y2];

        return full_name;
    }
    string GetFullNameWithHistory(int year) {
        const string first_name = getHistoryName(FindNamesHistory(names, year));
        const string last_name = getHistoryName(FindNamesHistory(surnames, year));

        if (first_name.empty() && last_name.empty())
            return "Incognito";
        else if (first_name.empty())
            return last_name + " with unknown first name";
        else if (last_name.empty())
            return first_name + " with unknown last name";

        return first_name + " " + last_name;
    }

private:
    map<int, string> names;
    map<int, string> surnames;

    vector<string> FindNamesHistory(map<int, string>& name_to_year, int year) {
        vector<string> n;
        string lastChangedName;

        for (const auto& [key, value] : name_to_year) {
            if (key > year) {
                break;
            }

            if (lastChangedName != value) {
                lastChangedName = value;
                n.push_back(value);
            }
        }

        return n;
    }

    string getHistoryName(vector<string> n) {
        string result;
        unsigned long size = names.size();

        if (size == 0)
            return result;

        reverse(n.begin(), n.end());
        result += n[0];

        if (size > 1) 
        {
            result += " (";
            for (int i = 1; i < size; ++i) 
            {
                result += n[i];

                if (i < size - 1)
                    result += ", ";
            }
            result += ')';
        }

        return result;
    }

    int GetPreviousChangeYear(map<int, string>& history, int year)
    {
        int y = 0;
        for (auto h: history)
        {
            if (h.first <= year)
            y = h.first;
        }
        return y;
    }
};

int main()
{
    Person person;
  
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
    
    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
    
    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
    
    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;
    
    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;
    
    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
    
    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;
    
    return 0;
}