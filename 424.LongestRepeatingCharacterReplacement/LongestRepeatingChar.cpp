#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * We focus on the **longest** possible string,
 * the length of which should be equal to max_freq + k
 * 
 * When the constraint is violated, since we have found at least one longest string,
 * we do not shrink the window, but instead shift it right by one unit
 * 
 * We only need to update the longest possible length whenever max_freq grows larger
 * because this indicates that a better solution is found
 */

class Solution {
   public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int max_freq = 0;
        int max_length = 0;
        int start = 0;
        for (int end = 0; end < s.size(); ++end) {
            freq[s[end]] += 1;
            max_freq = max(max_freq, freq[s[end]]);
            if (end - start + 1 - max_freq > k) {
                // constraint violated
                freq[s[start]] -= 1;
                ++start;
            }
            max_length = max(max_length, end - start + 1);
        }

        return max_length;
    }
};
