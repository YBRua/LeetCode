// 1343-number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold
#include <vector>

using namespace std;

class Solution {
   public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int k_threshold = k * threshold;
        int left = 0, right = 0;
        int running_sum = 0;
        int count = 0;

        while (right < arr.size()) {
            running_sum += arr[right];

            while (right - left + 1 > k) {
                running_sum -= arr[left];
                left++;
            }

            if (right - left + 1 == k && running_sum >= k_threshold) {
                count += 1;
            }

            right += 1;
        }

        return count;
    }
};
