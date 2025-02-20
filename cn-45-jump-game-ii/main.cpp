#include <vector>
using namespace std;

class Solution {
   public:
    int jump(vector<int>& nums) {
        vector<int> max_dists(nums.size(), 0);
        max_dists[0] = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            max_dists[i] = max(max_dists[i - 1], i + nums[i]);
        }

        int cnt = 0;
        int k = nums.size() - 1;
        while (k != 0) {
            for (int i = 0; i <= nums.size(); ++i) {
                if (max_dists[i] >= k) {
                    k = i;
                    break;
                }
            }
            cnt++;
        }

        return cnt;
    }
};
