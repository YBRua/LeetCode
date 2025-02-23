#include <string>
using namespace std;

class Solution {
   public:
    string convert(string s, int numRows) {
        string res;
        if (numRows == 1) {
            return s;
        }

        for (int row = 0; row < numRows; ++row) {
            int upper = row;
            int lower = numRows - row - 1;
            int ptr = row;

            while (ptr < s.size()) {
                if (lower && ptr < s.size()) {
                    res += s[ptr];
                    ptr += 2 * lower;
                }
                if (upper && ptr < s.size()) {
                    res += s[ptr];
                    ptr += 2 * upper;
                }
            }
        }

        return res;
    }
};
