#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> results(nums.size());
        int left = 0, right = nums.size() - 1;

        for (int i = 0; i < nums.size(); ++i) {
            int j = nums.size() - 1 - i;
            if (nums[i] < pivot) {
                results[left] = nums[i];
                left++;
            }
            if (nums[j] > pivot) {
                results[right] = nums[j];
                right--;
            }
        }

        while (left <= right) {
            results[left] = pivot;
            left++;
        }

        return results;
    }
};
