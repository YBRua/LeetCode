#include <vector>
using namespace std;
class Solution {
   public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> res;
        int len1 = nums1.size(), len2 = nums2.size();

        int ptr1 = 0, ptr2 = 0;
        while (ptr1 < len1 && ptr2 < len2) {
            if (nums1[ptr1][0] == nums2[ptr2][0]) {
                res.push_back({nums1[ptr1][0], nums1[ptr1][1] + nums2[ptr2][1]});
                ptr1++;
                ptr2++;
            } else if (nums1[ptr1][0] < nums2[ptr2][0]) {
                res.push_back({nums1[ptr1][0], nums1[ptr1][1]});
                ptr1++;
            } else if (nums1[ptr1][0] > nums2[ptr2][0]) {
                res.push_back({nums2[ptr2][0], nums2[ptr2][1]});
                ptr2++;
            }
        }

        while (ptr1 < len1) {
            res.push_back({nums1[ptr1][0], nums1[ptr1][1]});
            ptr1++;
        }
        while (ptr2 < len2) {
            res.push_back({nums2[ptr2][0], nums2[ptr2][1]});
            ptr2++;
        }

        return res;
    }
};
