#include <vector>
using namespace std;

class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, k = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
                k++;
            }
        }

        return k;
    }
};
