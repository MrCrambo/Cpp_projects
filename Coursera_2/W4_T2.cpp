#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s);

vector<string> SplitIntoWords(const string& s)
{
    vector<string> words;
    auto it_beign = s.begin();
    auto it_end = find(s.begin(), s.end(), ' ');
    while (it_end != s.end())
    {
        words.emplace_back(string(it_beign, it_end));
        it_beign = it_end + 1;
        it_end = find(it_beign, s.end(), ' ');
    }
    words.emplace_back(string(it_beign, s.end()));

    return words; 
}

int main()
{
    string s = "C Cpp Java Python";

    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) 
    {
        if (it != begin(words))
            cout << "/";
        cout << *it;
    }
    cout << endl;
    
    return 0;
}