#include <array>
#include <cstdint>
#include <iterator>
#include <numeric>
#include <vector>
#include <utility>
#include <list>

using namespace std;

template <typename Container, typename ForwardIt>
ForwardIt LoopIterator(Container& container, ForwardIt pos)
{
    return pos == container.end() ? container.begin() : pos;
}

template <typename RandomIt>
void MakeJosephusPermutation(RandomIt first, RandomIt last, uint32_t step_size) 
{
    list<typename RandomIt::value_type> pool;
    move(first, last, back_inserter(pool));
    auto cur = pool.begin();
    while (!pool.empty()) 
    {
        *(first++) = move(*cur);
        if(pool.size() == 1)
        {
            break;
        }
        const auto next_pos = LoopIterator(pool, next(cur));
        pool.erase(cur);
        cur = next_pos;
        for(uint32_t step_index = 1; step_index < step_size; ++step_index)
        {
            cur = LoopIterator(pool, next(cur));
        }
    }
}