#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end)
{
    if(range_end - range_begin > 1)
    {
        vector<typename RandomIt::value_type> elements(range_begin, range_end);
        RandomIt middle_It = elements.begin() + elements.size() / 2;
        MergeSort(begin(elements), middle_It);
        MergeSort(middle_It, end(elements));

        merge(begin(elements), middle_It, middle_It, end(elements), range_begin);
    }
    return;
}

int main() 
{
    return 0;
}