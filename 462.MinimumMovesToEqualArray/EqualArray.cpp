// 462. Minimum Moves to Equal Array Elements II
// <https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/>
// The idea is that we should move all elements to the median

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
