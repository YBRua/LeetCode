#include <vector>
#include <algorithm>

using namespace std;


// <https://leetcode.com/problems/frequency-of-the-most-frequent-element/discuss/1175088/C%2B%2B-Maximum-Sliding-Window-Cheatsheet-Template!>
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // sliding window with shrinking:
        // window grows when the state is valid
        // and shrinks until the window is invalid
        sort(nums.begin(), nums.end());
        int sum = 0, i = 0, j = 0, max_val = 0;
        // we want to increase the numbers in nums[i:j] to be equal to j
        while (j < nums.size()) {
            sum += nums[j];
            while (nums[j] * (j - i + 1) - sum > k) {
                sum -= nums[i];
                ++i;
            }
            max_val = max(max_val, j - i + 1);
            ++j;
        }

        return max_val;
    }
};
