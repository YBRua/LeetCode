// 3208-alternating-groups-ii

#include <vector>
using namespace std;

class Solution {
   public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n_alternating_groups = 0;

        int left = 0, right = 0;
        int n = colors.size();
        while (right < n + k - 1) {
            if (right > 0 && colors[right % n] == colors[(right - 1) % n]) {
                left = right;
            }
            if (right - left + 1 >= k) {
                n_alternating_groups++;
            }

            right++;
        }

        return n_alternating_groups;
    }
};
