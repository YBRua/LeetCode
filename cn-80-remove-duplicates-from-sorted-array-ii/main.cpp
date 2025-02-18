#include <vector>
using namespace std;

class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        const int NUM_PER_ITEM = 2;

        int next_p = 0;
        int k = 0;  // new length

        if (!nums.size()) {
            return 0;
        }

        while (next_p < nums.size()) {
            // 1. copy values && find boundary
            int anchor_v = nums[next_p];
            int count = 0;
            while (next_p < nums.size() && count < NUM_PER_ITEM && nums[next_p] == anchor_v) {
                nums[k++] = nums[next_p++];
                count++;
            }

            // 2. find next value
            while (next_p < nums.size() && nums[next_p] == anchor_v) {
                next_p++;
            }
        }

        return k;
    }
};
