#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last_pos;
        unordered_set<char> active;
        vector<int> res;
        
        // preprocess: get the last id of each char
        for (int i = s.size() - 1; i >= 0; --i) {
            char current = s[i];
            if (!last_pos.count(current)) {
                last_pos[current] = i;
            }
        }

        int length = 1;
        for (int i = 0; i < s.size(); ++i, ++length) {
            char current = s[i];
            active.emplace(current);

            // remove from active if it will not appear
            if (i == last_pos[current]) {
                active.erase(current);
            }

            // if active is empty, we can split
            if (!active.size()) {
                res.push_back(length);
                length = 0;
            }
        }

        return res;
    }
};
