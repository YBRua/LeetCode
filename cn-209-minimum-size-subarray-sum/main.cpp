#include <vector>
using namespace std;

class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int current_sum = 0;
        int min_length = 1919810;
        int begin = 0, end = 0;

        while (end < nums.size()) {
            current_sum += nums[end];
            while (begin <= end && current_sum >= target) {
                min_length = min(min_length, end - begin + 1);
                current_sum -= nums[begin];
                begin++;
            }

            end++;
        }

        return min_length == 1919810 ? 0 : min_length;
    }
};

int main() {
    auto nums = vector<int>{1, 4, 4};
    Solution solver;
    solver.minSubArrayLen(4, nums);
}