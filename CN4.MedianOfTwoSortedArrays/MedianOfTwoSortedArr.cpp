#include <vector>

using namespace std;

class Solution {
   public:
    int _find_kth_smallest(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1 = nums1.size(), len2 = nums2.size();
        int idx1 = 0, idx2 = 0;

        while (true) {
            if (idx1 == len1) return nums2[idx2 + k - 1];
            if (idx2 == len2) return nums1[idx1 + k - 1];
            if (k == 1) return min(nums1[idx1], nums2[idx2]);

            int tgt = k / 2 - 1;
            int new_idx1 = min(idx1 + tgt, len1 - 1);
            int new_idx2 = min(idx2 + tgt, len2 - 1);
            if (nums1[new_idx1] < nums2[new_idx2]) {
                // first k/2 - 1 elements of nums1 all < median
                // so none of them can be the median
                k -= new_idx1 - idx1 + 1;
                idx1 = new_idx1 + 1;
            } else {
                // first k/2 - 1 elements of nums2 all < median
                k -= new_idx2 - idx2 + 1;
                idx2 = new_idx2 + 1;
            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n_elements = nums1.size() + nums2.size();
        if (n_elements % 2 == 0) {
            return (_find_kth_smallest(nums1, nums2, n_elements / 2) +
                    _find_kth_smallest(nums1, nums2, n_elements / 2 + 1)) /
                   2.0;
        } else {
            return _find_kth_smallest(nums1, nums2, (n_elements + 1) / 2);
        }
    }
};
