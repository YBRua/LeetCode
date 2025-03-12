// 1358-number-of-substrings-containing-all-three-characters
#include <string>
using namespace std;

class Solution {
   public:
    int numberOfSubstrings(string s) {
        int n = 0;
        int left = 0, right = 0;
        int counter[3];

        while (right < s.size()) {
            counter[s[right] - 'a']++;

            if (counter[0] > 0 && counter[1] > 0 && counter[2] > 0) {
                n += s.size() - right;
            }

            while (counter[0] > 0 && counter[1] > 0 && counter[2] > 0) {
                counter[s[left] - 'a']--;
                left++;
                if (counter[0] > 0 && counter[1] > 0 && counter[2] > 0) {
                    n += s.size() - right;
                }
            }

            right++;
        }

        return n;
    }
};
