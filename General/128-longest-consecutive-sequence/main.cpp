// 128-longest-consecutive-sequence
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int longest_consecutive = 0;
        for (int num : s) {
            if (s.find(num - 1) == s.end()) {
                int current = 0;
                while (s.find(num) != s.end()) {
                    ++current;
                    ++num;
                }

                longest_consecutive = max(longest_consecutive, current);
            }
        }

        return longest_consecutive;
    }
};
