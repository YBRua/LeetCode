// 2379-minimum-recolors-to-get-k-consecutive-black-blocks

#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int minimumRecolors(string blocks, int k) {
        int left = 0, right = 0;
        int n = blocks.length();

        int min_recolors = INT_MAX;
        int n_whites = 0;

        while (right < n) {
            char curr = blocks[right];
            if (curr == 'W') {
                n_whites++;
            }
            right++;

            if (right - left == k) {
                min_recolors = min(min_recolors, n_whites);
                if (blocks[left] == 'W') {
                    n_whites--;
                }
                left++;
            }
        }

        return min_recolors;
    }
};
