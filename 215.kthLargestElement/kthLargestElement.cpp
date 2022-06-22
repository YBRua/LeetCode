#include <vector>
#include <cstdio>

using namespace std;

class Solution {
   public:
    int _split(vector<int>& nums, int start, int end, int pivot) {
        int lp = start, rp = end;

        while (lp < rp) {
            while (lp < rp && nums[rp] <= pivot) {
                rp--;
            }
            while (lp < rp && nums[lp] >= pivot) {
                lp++;
            }
            if (lp < rp) {
                int tmp = nums[lp];
                nums[lp] = nums[rp];
                nums[rp] = tmp;
            }
        }

        nums[start] = nums[lp];
        nums[lp] = pivot;

        return lp;
    }

    int _quickSelectWrapper(vector<int>& nums, int start, int end, int k) {
        int pivot = nums[start];
        int split = _split(nums, start, end, pivot);
        if (split == k) {
            return nums[k];
        } else if (split < k) {
            return _quickSelectWrapper(nums, split + 1, end, k);
        } else {
            return _quickSelectWrapper(nums, start, split - 1, k);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        return _quickSelectWrapper(nums, 0, nums.size() - 1, k - 1);
    }
};

int main() {
    vector<int> test_case = {3, 2, 1, 5, 6, 4};
    int k = 2;
    int res = Solution().findKthLargest(test_case, k);
    printf("%d\n", res);
}