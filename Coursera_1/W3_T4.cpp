#include <iostream>
#include <map>

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
private:
    map<int, string> names;
    map<int, string> surnames;

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
        cout << person.GetFullName(year) << endl;
    }
    
    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
    
    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
    
    return 0;
}