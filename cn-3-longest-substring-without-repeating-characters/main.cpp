#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> counter;
        int start = 0, end = 0;
        int max_length = 0;
        while (end < s.length()) {
            counter[s[end]]++;
            while (start <= end && counter[s[end]] > 1) {
                counter[s[start]]--;
                start++;
            }
            end++;

            max_length = max(max_length, end - start);
        }

        return max_length;
    }
};
