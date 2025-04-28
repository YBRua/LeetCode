// 2090-k-radius-subarray-averages
#include <cmath>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int left = -k, right = -k;
        int running_sum = 0;
        auto res = vector<int>();

        while (res.size() < nums.size()) {
            if (left < 0) {
                if (right >= 0 && right < nums.size()) {
                    running_sum += nums[right];
                }

                if (right - left + 1 > 2 * k + 1) {
                    left++;
                }

                if (right - left + 1 == 2 * k + 1) {
                    res.push_back(-1);
                }

                right++;
            } else {
                if (right >= 0 && right < nums.size()) {
                    running_sum += nums[right];
                }

                if (right - left + 1 > 2 * k + 1) {
                    running_sum -= nums[left];
                    left++;
                }

                if (right - left + 1 == 2 * k + 1) {
                    if (right >= 0 && right < nums.size()) {
                        res.push_back(std::floor(running_sum / (2 * k + 1)));
                    } else {
                        res.push_back(-1);
                    }
                }
                right++;
            }
        }

        return res;
    }
};