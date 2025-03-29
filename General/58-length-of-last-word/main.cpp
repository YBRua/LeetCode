#include <cctype>
#include <string>

class Solution {
   public:
    int lengthOfLastWord(std::string s) {
        int len = 0;
        auto it = s.rbegin();
        while (it != s.rend()) {
            // skip trailing spaces
            while (it != s.rend() && *it == ' ') {
                it++;
            }
            // count chars
            while (it != s.rend() && *it != ' ') {
                len++;
                it++;
            }
            break;
        }

        return len;
    }
};
