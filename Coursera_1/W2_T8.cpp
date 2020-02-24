#include <iostream>
#include <set>
#include <map>

using namespace std;

int main()
{   
    set<set<string> > sinonims;
    map<string, int> words;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string operation;
        cin >> operation;

        if (operation == "ADD")
        {
            string first, second;
            cin >> first >> second;
            if (sinonims.count({first, second}) == 0)
            {
                words[first]++;
                words[second]++;
            }
            
            sinonims.insert({first, second});
        }
        else if (operation == "COUNT")
        {
            string word;
            cin >> word;
            cout << words[word] << endl;
        }
        else
        {
            string first, second;
            cin >> first >> second;
            if (sinonims.count({first, second}) == 0)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        } 
    }

    return 0;
}