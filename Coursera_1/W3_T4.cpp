#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
public:
    Person(string name, string surname, int year)
    {
        name = name;
        surname = surname;
        burn_year = year;
        names[year] = name;
        surnames[year] = surname;
    }

    void ChangeFirstName(int year, const string& first_name) 
    {
        if (year < burn_year)
            return;

        if (names.count(year) == 0)
            names[year] = first_name;
    }

    void ChangeLastName(int year, const string& last_name) 
    {
        if (year < burn_year)
            return;

        if (surnames.count(year) == 0)
            surnames[year] = last_name;
    }
    string GetFullName(int year) const
    {
        if (year < burn_year)
            return "No person";
        
        const vector<string> first_names = FindNamesHistory(names, year);
        const vector<string> last_names = FindNamesHistory(surnames, year);

        string first_name;
        string last_name;

        if (!first_names.empty())
            first_name = first_names.back();

        if (!last_names.empty())
            last_name = last_names.back();

        if (first_name.empty() && last_name.empty())
            return "Incognito";
        else if (first_name.empty())
            return last_name + " with unknown first name";
        else if (last_name.empty())
            return first_name + " with unknown last name";

        return first_name + " " + last_name;
    }

    string GetFullNameWithHistory(int year) const
    {
        if (year < burn_year)
            return "No person";

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
    string name, surname;
    int burn_year;
    map<int, string> names;
    map<int, string> surnames;

    vector<string> FindNamesHistory(const map<int, string>& name_to_year, int year) const
    {
        vector<string> n;
        string lastChangedName;

        for (const auto& name : name_to_year) {
            if (name.first > year)
                break;

            if (lastChangedName != name.second) {
                lastChangedName = name.second;
                n.push_back(name.second);
            }
        }

        return n;
    }

    string getHistoryName(vector<string> n) const
    {
        string result;
        unsigned long size = n.size();

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

    int GetPreviousChangeYear(const map<int, string>& history, int year) const
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
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }
    
    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
    
}