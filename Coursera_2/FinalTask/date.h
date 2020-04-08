#ifndef YELLOW_BELT_DATE_H
#define YELLOW_BELT_DATE_H

#include <exception>
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class Date 
{
public:
    Date(int new_day, int new_month, int new_year);

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
    int year;
    int month;
    int day;
};

bool operator<(const Date& lhs, const Date& rhs);

bool operator!=(const Date& lhs, const Date& rhs);

bool operator==(const Date& lhs, const Date& rhs);

std::ostream& operator<<(std::ostream& stream, const Date& date);

Date ParseDate(std::istream &is);

void TestParseDate();
#endif //YELLOW_BELT_DATE_H