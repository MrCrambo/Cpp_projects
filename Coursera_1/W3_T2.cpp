#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> words(n);
    for (auto& w: words)
    {
        cin >> w;
    }

    sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
        for (int c = 0; c < a.size() && c < b.size(); c++) {
            if (tolower(a[c]) != tolower(b[c]))
                return (tolower(a[c]) < tolower(b[c]));
        }
        return a.size() < b.size();
    });

    for (auto& w: words)
    {
        cout << w << " ";
    }
    

    return 0;
}