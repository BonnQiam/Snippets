#include <unordered_map>

std::pair<std::size_t, std::size_t> two_sum(const std::vector<int>& numbers, int target) {
    std::unordered_map<int, std::size_t> counterparts;
    for (std::size_t i = 0; i < numbers.size(); ++i) {
        auto it = counterparts.find(numbers[i]);
        if (it != counterparts.end())
            return {it->second, i};
        counterparts.emplace(target - numbers[i], i);
    }
    return {-1, -1};
}