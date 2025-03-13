// 205-isomorphic-strings
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s_to_t;
        unordered_map<char, char> t_to_s;

        if (s.size() != t.size()) {
            return false;
        }

        for (int i = 0; i < s.size(); ++i) {
            // check s-to-t integrity
            if (s_to_t.find(s[i]) == s_to_t.end()) {
                s_to_t[s[i]] = t[i];
            } else {
                if (s_to_t.at(s[i]) != t[i]) {
                    return false;
                }
            }

            // check t-to-s integrity
            if (t_to_s.find(t[i]) == t_to_s.end()) {
                t_to_s[t[i]] = s[i];
            } else {
                if (t_to_s.at(t[i]) != s[i]) {
                    return false;
                }
            }
        }

        return true;
    }
};
