#include <iostream>
#include <map>
#include <exception>

using namespace std;

template <typename F, typename S> S& GetRefStrict(map<F, S>& m, F k)
{
    if (m.count(k) == 0)
    {
        throw runtime_error("");
    }
    return m.at(k);
}

int main()
{
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl; // выведет newvalue

    return 0;
}