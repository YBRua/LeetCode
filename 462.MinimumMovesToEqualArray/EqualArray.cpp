#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int target = nums[nums.size() / 2];
        int moves = 0;
        for (auto val: nums) {
            moves += abs(val - target);
        }

        return moves;
    }
};
