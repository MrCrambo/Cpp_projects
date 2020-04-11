#include "airline_ticket.h"
#include "test_runner.h"

#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

// Macro and definition of operators added

#define SORT_BY(field)                                      \
    [](const AirlineTicket& lhs, const AirlineTicket& rhs) {\
    return lhs.field < rhs.field;                           \
}

bool operator<(const Date& lhs, const Date& rhs)
{
    return vector<int>{lhs.year, lhs.month, lhs.day} < vector<int>{rhs.year, rhs.month, rhs.day };
}

bool operator==(const Date& lhs, const Date& rhs)
{
    return vector<int>{lhs.year, lhs.month, lhs.day} == vector<int>{rhs.year, rhs.month, rhs.day };
}

ostream& operator<<(ostream& os, const Date& d)
{
   os << d.year << "-" << d.month << "-" << d.day;
   return os;
}

bool operator<(const Time& lhs, const Time& rhs)
{
    return lhs.hours * 60 + lhs.minutes < rhs.hours * 60 + rhs.minutes;
}

bool operator==(const Time& lhs, const Time& rhs)
{
    return lhs.hours == rhs.hours && lhs.minutes == rhs.minutes;
}

ostream& operator<<(ostream& os, const Time& t)
{
    os << t.hours << ":" << t.minutes;
    return os;
}

void TestSortBy() 
{
  vector<AirlineTicket> tixs = 
  {
    {"VKO", "AER", "Utair",     {2018, 2, 28}, {17, 40}, {2018, 2, 28}, {20,  0}, 1200},
    {"AER", "VKO", "Utair",     {2018, 3,  5}, {14, 15}, {2018, 3,  5}, {16, 30}, 1700},
    {"AER", "SVO", "Aeroflot",  {2018, 3,  5}, {18, 30}, {2018, 3,  5}, {20, 30}, 2300},
    {"PMI", "DME", "Iberia",    {2018, 2,  8}, {23, 00}, {2018, 2,  9}, { 3, 30}, 9000},
    {"CDG", "SVO", "AirFrance", {2018, 3,  1}, {13, 00}, {2018, 3,  1}, {17, 30}, 8000},
  };

  sort(begin(tixs), end(tixs), SORT_BY(price));
  ASSERT_EQUAL(tixs.front().price, 1200);
  ASSERT_EQUAL(tixs.back().price, 9000);

  sort(begin(tixs), end(tixs), SORT_BY(from));
  ASSERT_EQUAL(tixs.front().from, "AER");
  ASSERT_EQUAL(tixs.back().from, "VKO");

  sort(begin(tixs), end(tixs), SORT_BY(arrival_date));
  ASSERT_EQUAL(tixs.front().arrival_date, (Date{2018, 2, 9}));
  ASSERT_EQUAL(tixs.back().arrival_date, (Date{2018, 3, 5}));

  sort(begin(tixs), end(tixs), SORT_BY(arrival_time));
  ASSERT_EQUAL(tixs.front().arrival_time, (Time{3, 30}));
  ASSERT_EQUAL(tixs.back().arrival_time, (Time{20, 30}));
}

int main() 
{
  TestRunner tr;
  RUN_TEST(tr, TestSortBy);
}
