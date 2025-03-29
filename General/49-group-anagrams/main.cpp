#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;

        for (string& str : strs) {
            string key = "00000000000000000000000000";
            for (char c : str) {
                key[c - 'a'] += 1;
            }

            res[key].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto& [key, val] : res) {
            ans.push_back(val);
        }

        return ans;
    }
};
