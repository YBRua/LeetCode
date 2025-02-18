#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counter;
        int candidate = 0, count = 0;

        for (auto num : nums) {
            counter[num]++;
            if (counter[num] > count) {
                candidate = num;
                count = counter[num];
            }
        }

        return candidate;
    }
};
