#include <vector>
using namespace std;

class Solution {
   public:
    int divide(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int lp = left, rp = right;

        while (lp < rp) {
            // find first element smaller than pivot from right
            while (lp < rp && nums[rp] >= pivot) {
                rp--;
            }
            if (lp < rp) {
                nums[lp] = nums[rp];
                lp++;
            }
            // find first element larger than pivot from left
            while (lp < rp && nums[lp] <= pivot) {
                lp++;
            }
            if (lp < rp) {
                nums[rp] = nums[lp];
                rp--;
            }
        }
        nums[lp] = pivot;

        return lp;
    }

    int quickSelect(vector<int>& nums, int k, int start, int end) {
        while (true) {
            int pivot_pos = divide(nums, start, end);
            if (pivot_pos == k) {
                return nums[pivot_pos];
            } else if (pivot_pos < k) {
                start = pivot_pos + 1;
            } else {
                end = pivot_pos - 1;
            }
        }
    }

    int findKthLargest(vector<int>& nums, int k) { return quickSelect(nums, k - 1, 0, nums.size() - 1); }
};
