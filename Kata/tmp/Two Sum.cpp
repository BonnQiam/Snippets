// https://www.codewars.com/kata/52c31f8e6605bcc646000082/train/cpp

#include <vector>
#include <utility>

std::pair<std::size_t, std::size_t> two_sum(const std::vector<int>& numbers, int target) {

    std::pair<std::size_t, std::size_t> result;

    for (std::size_t i = 0; i < numbers.size(); i++) {
        for (std::size_t j = i + 1; j < numbers.size(); j++) {
            if (numbers[i] + numbers[j] == target) {
                result.first = i;
                result.second = j;
                return result;
            }
        }
    }

    //return {0, 0};
}