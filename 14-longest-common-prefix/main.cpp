#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        for (int i = 0; i < strs[0].size(); ++i) {
            char candidate = strs[0][i];

            for (int j = 0; j < strs.size(); ++j) {
                if (i >= strs[j].size() || strs[j][i] != candidate) {
                    return res;
                }
            }
            res += candidate;
        }

        return res;
    }
};
