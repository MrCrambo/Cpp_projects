#include <algorithm>
#include <memory>
#include <vector>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) 
{
    if(range_end - range_begin < 2)
        return;

    vector<typename RandomIt::value_type> v = {make_move_iterator(range_begin), make_move_iterator(range_end)};

    RandomIt endPart1_it = v.begin() + v.size() / 3;
    RandomIt endPart2_it = endPart1_it + v.size() / 3;

    MergeSort(v.begin(), endPart1_it);
    MergeSort(endPart1_it, endPart2_it);
    MergeSort(endPart2_it, v.end());

    vector<typename RandomIt::value_type> tmp_v;
    merge(make_move_iterator(begin(v)), make_move_iterator(endPart1_it),
            make_move_iterator(endPart1_it), make_move_iterator(endPart2_it),
            back_inserter(tmp_v));

    merge(make_move_iterator(begin(tmp_v)), make_move_iterator(end(tmp_v)),
            make_move_iterator(endPart2_it), make_move_iterator(end(v)),
            range_begin);
}