#include <vector>
using namespace std;

class Solution {
   public:
    int jump(vector<int>& nums) {
        int border = 0;
        int max_dist = 0;
        int steps = 0;
        for (int i = 0; i < nums.size(); ++i) {
            max_dist = max(max_dist, i + nums[i]);
            if (i == border) {
                border = max_dist;
                steps += 1;
            }
        }

        return steps;
    }
};
