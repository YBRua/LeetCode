#include <climits>
#include <cstdio>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    // O(nk), but this algorithms TLEs
    // int maxResult(vector<int>& nums, int k) {
    //     vector<int> res(nums.size(), 0);
    //     res[0] = nums[0];
    //     for (int i = 1; i < nums.size(); ++i) {
    //         int max_val = INT_MIN;
    //         for (int j = 1; j <= k; ++j) {
    //             if (i - j >= 0) {
    //                 max_val = max(max_val, res[i - j]);
    //             }
    //         }
    //         res[i] = max_val + nums[i];
    //     }
    //     return res[res.size() - 1];
    // }

    int maxResult(vector<int>& nums, int k) {
        vector<int> res(nums.size(), 0);
        res[0] = nums[0];

        // chihao happy max (monotonic-decreasing) queue
        deque<int> chmq;

        chmq.push_back(0);
        for (int i = 1; i < nums.size(); ++i) {
            // remove out-dated values
            while (chmq.size() && i - chmq.front() > k) {
                chmq.pop_front();
            }
            int max_val = res[chmq.front()] + nums[i];
            while (chmq.size() && res[chmq.back()] < max_val) {
                chmq.pop_back();
            }
            res[i] = max_val;
            chmq.push_back(i);
        }

        return res[nums.size() - 1];
    }
};

int main() {
    vector<int> nums = {10, -5, -2, 4, 0, 3};
    int k = 3;
    printf("%d\n", Solution().maxResult(nums, k));

    return 0;
}
