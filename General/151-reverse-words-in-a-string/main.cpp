#include <cctype>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    string reverseWords(string s) {
        vector<string> buffer;
        int ptr = 0;

        while (ptr < s.size()) {
            // skip spaces
            while (ptr < s.size() && s[ptr] == ' ') {
                ptr++;
            }
            string word;
            while (ptr < s.size() && isalnum(s[ptr])) {
                word += s[ptr];
                ptr++;
            }
            buffer.push_back(word);
        }

        string res;
        for (auto it = buffer.rbegin(); it != buffer.rend(); ++it) {
            if (!res.size()) {
                res = *it;
            } else {
                res = res + " " + *it;
            }
        }

        return res;
    }
};
