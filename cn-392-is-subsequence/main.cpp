#include <string>
using namespace std;

class Solution {
   public:
    bool isSubsequence(string s, string t) {
        if (!s.size()) {
            return true;
        }

        int sp = 0, tp = 0;
        while (sp < s.size() && tp < t.size()) {
            if (s[sp] == t[tp]) {
                sp++;
            }
            tp++;
        }

        if (sp != s.size()) {
            return false;
        }

        return true;
    }
};
