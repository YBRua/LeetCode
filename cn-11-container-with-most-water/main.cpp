#include <vector>
using namespace std;

class Solution {
   public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_capacity = 0;

        while (left < right) {
            int capacity = min(height[left], height[right]) * (right - left);
            max_capacity = max(max_capacity, capacity);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_capacity;
    }
};