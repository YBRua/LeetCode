#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0, high = numbers.size() - 1;
        while (low <= high) {
            if (numbers[low] + numbers[high] > target) {
                high--;
            }
            if (numbers[low] + numbers[high] < target) {
                low++;
            }
            if (numbers[low] + numbers[high] == target) {
                return {low + 1, high + 1};
            }
        }

        return {};
    }
};
