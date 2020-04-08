#include "database.h"

#include <algorithm>

void Database::Add(const Date &date, const std::string &event) 
{
    auto range_begin = storage[date].begin();
    auto range_end = storage[date].end();
    if(set_storage[date].count(event) == 0)
    {
        storage[date].push_back(event);
        set_storage[date].insert(event);
    }
}

void Database::Print(std::ostream &os) const 
{
    for (const auto& item : storage) 
    {
        for (const std::string& event : item.second) 
        {
            os << item.first << " " << event << std::endl;
        }
    }
}

int Database::RemoveIf(std::function<bool (const Date&, const std::string&)> predicate)
{
    std::vector<Entry> entries;
    int count_del_notes = 0;
    std::map<Date, std::vector<std::string>> new_storage;
    std::map<Date, std::set<std::string>> new_set_storage;
    for(const auto& [key, value] : storage )
    {
        for(const auto& event : value)
        {
            if(!predicate(key, event))
            {
                new_storage[key].push_back(event);
                new_set_storage[key].insert(event);
            }
            else
            {
                count_del_notes++;
            }
        }
    }
    storage = new_storage;
    set_storage = new_set_storage;
    return count_del_notes;
}

std::vector<Entry> Database::FindIf(std::function<bool (const Date&, const std::string&)> predicate)const
{
    std::vector<Entry> entries;
    for(const auto& [key, value] : storage )
    {
        for(const auto& event : value)
        {
            if(predicate(key, event))
            {
                entries.emplace_back(std::make_pair(key, event));
            }
        }
    }
    return entries;
}

Entry Database::Last(const Date& date)const
{
    auto last_entry_it = storage.lower_bound(date);
    if(last_entry_it->first == date)
        return std::make_pair(last_entry_it->first, last_entry_it->second.back());

    if(last_entry_it != storage.begin())
    {
        last_entry_it = prev(last_entry_it);
        return std::make_pair(last_entry_it->first, last_entry_it->second.back());
    }
    throw std::invalid_argument("No entries");
}


std::ostream& operator<<(std::ostream& os, const Entry& e)
{
    os << e.first << " " << e.second;
    return os;
}
