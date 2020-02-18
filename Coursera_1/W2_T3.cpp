#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> Reversed(const vector<int>& input)
{
    vector<int> result;
    for (int i = input.size() - 1; i >= 0; --i) {
        result.push_back(input[i]);
    }
    return result;
}

void Reverse(vector<int>& v)
{
    for (int i = 0; i < v.size() / 2; i++)
    {
        int temp = v[v.size() - i - 1];
        v[v.size() - i - 1] = v[i];
        v[i] = temp;
    }
}

void MoveStrings(vector<string>& source, vector<string>& destination)
{
    for (auto el: source)
    {
        destination.push_back(el);
    }
    source.clear();
}

int main()
{
    return 0;
}