#include <string>

using namespace std;

class Solution {
    // 1456-maximum-number-of-vowels-in-a-substring-of-given-length
   public:
    inline bool is_vowel(char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; }

    int maxVowels(string s, int k) {
        int left = 0, right = 0, max_vowels = 0, curr_vowels = 0;
        while (right < s.size()) {
            if (is_vowel(s[right])) {
                curr_vowels++;
            }

            while (right - left + 1 > k) {
                if (is_vowel(s[left])) {
                    curr_vowels--;
                }
                left += 1;
            }

            if (right - left + 1 == k) {
                max_vowels = max(max_vowels, curr_vowels);
            }

            right++;
        }

        return max_vowels;
    }
};