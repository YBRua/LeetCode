#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> res(26, 0);
        int max_val = 1;
        for (int i = 0; i < p.size(); ++i) {
            if (i > 0 && (p[i - 1] - 'a' + 1) % 26 == p[i] - 'a') {
                max_val++;
            } else {
                max_val = 1;
            }
            res[p[i] - 'a'] = max(max_val, res[p[i] - 'a']);
        }

        int sums = 0;
        for (int i = 0; i < res.size(); ++i) {
            sums += res[i];
        }

        return sums;
    }
};
