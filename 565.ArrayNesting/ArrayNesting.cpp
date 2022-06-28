#include <unordered_set>
#include <vector>

using namespace std;

// TLE!
// class Solution {
// public:
//     vector<int> res_cache;

//     int array_explore(int node, vector<int>& nums, unordered_set<int>&
//     visited) {
//         if (visited.count(node)) {
//             return 0;
//         } else {
//             if (res_cache[node] != 0) {
//                 return res_cache[node];
//             } else {
//                 visited.emplace(node);
//                 return 1 + array_explore(nums[node], nums, visited);
//             }

//         }
//     }

//     int arrayNesting(vector<int>& nums) {
//         res_cache.clear();
//         res_cache.resize(nums.size(), 0);
//         unordered_set<int> visited;
//         int max_res = 0;
//         for (int i = 0; i < nums.size(); ++i) {
//             visited.clear();
//             int current_res = array_explore(nums[i], nums, visited);
//             max_res = max(max_res, current_res);
//             for (auto i = visited.begin(); i != visited.end(); ++i) {
//                 res_cache[*i] = current_res;
//             }
//         }

//         return max_res;
//     }
// };

class Solution {
   public:
    int arrayNesting(vector<int>& nums) {
        int max_size = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int next = i;
            int size = 0;
            while (nums[next] != -1) {
                int tmp = nums[next];
                nums[next] = -1;
                next = tmp;
                size++;
            }
            max_size = max(size, max_size);
        }
        return max_size;
    }
};
