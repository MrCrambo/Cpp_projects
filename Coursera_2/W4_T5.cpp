#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
  int range_length = range_end - range_begin;
  if (range_length < 2)
    return;
  
  vector<typename RandomIt::value_type> elements(range_begin, range_end);
  
  auto one_third = elements.begin() + range_length / 3;
  auto two_third = elements.begin() + range_length * 2 / 3;
  
  MergeSort(elements.begin(), one_third);
  MergeSort(one_third, two_third);
  MergeSort(two_third, elements.end());
  
  vector<typename RandomIt::value_type> interim_result;
  merge(elements.begin(), one_third, one_third, two_third,
        back_inserter(interim_result));

  merge(interim_result.begin(), interim_result.end(), two_third, elements.end(),range_begin);
}

int main() {
    return 0;
}