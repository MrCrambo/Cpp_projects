#include <iostream>
#include <utility>
#include <map>
#include <vector>

using namespace std;

template<typename T> T Sqr(T& t);
template <typename T> vector<T> Sqr(vector<T>& v);
template<typename F, typename S>  pair<F, S> Sqr(pair<F, S>& x);
template<typename F, typename S>  map<F, S> Sqr(map<F, S>& m);

template<typename T> 
T Sqr(T& t)
{
    return t * t;
}

template <typename T> 
vector<T> Sqr(vector<T>& v){
	for(auto& item: v){
		item = Sqr(item);
	}
	return v;
}

template<typename F, typename S> 
pair<F, S> Sqr(pair<F, S>& x)
{
    x.first = Sqr(x.first);
    x.second = Sqr(x.second);
    return x;
}

template<typename F, typename S> 
map<F, S> Sqr(map<F, S>& m)
{
    for (auto& item : m)
    {
        item.second = Sqr(item.second);
    }
    return m;
}

int main()
{
    vector< vector<int>> v = {{1, 2, 4}, {1, 2, 4}};
    cout << "vector:";
    for (vector<int> x : Sqr(v)) {
        for (int i: x)
        {
            cout << ' ' << i;
        }
        
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
        {4, {2, 2}},
        {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
    cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }

    return 0;
}