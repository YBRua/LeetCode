#include <string>
#include <unordered_map>

using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> counter;
        int left = 0, right = 0;
        int max_len = 0;
        while (right < s.length()) {
            counter[s[right]]++;
            while (left <= right && counter[s[right]] > 1) {
                counter[s[left]]--;
                left++;
            }
            max_len = max(max_len, right - left + 1);
            right++;
        }
        return max_len;
    }
};
