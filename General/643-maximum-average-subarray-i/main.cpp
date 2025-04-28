// 643-maximum-average-subarray-i
#include <limits>
#include <vector>

using namespace std;

class Solution {
   public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0, right = 0;
        double max_avg = numeric_limits<double>::lowest(), sum = 0.0;

        while (right < nums.size()) {
            sum += nums[right];

            while (right - left + 1 > k) {
                sum -= nums[left];
                left++;
            }

            if (right - left + 1 == k) {
                max_avg = max(max_avg, double(sum) / k);
            }

            right++;
        }

        return max_avg;
    }
};