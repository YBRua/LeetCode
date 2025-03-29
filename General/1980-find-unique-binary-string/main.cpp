#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    int binaryStringToInt(const string& s) {
        int base = 1;
        int value = 0;

        for (int i = s.size() - 1; i >= 0; --i) {
            char current = s[i];
            if (s[i] == '1') {
                value += base;
            }
            base *= 2;
        }

        return value;
    }

    string intToBinaryString(int value, int n) {
        vector<char> builder;
        while (value > 0) {
            if (value % 2 == 0) {
                builder.push_back('0');
            } else {
                builder.push_back('1');
            }
            value = value / 2;
        }
        while (builder.size() < n) {
            builder.push_back('0');
        }

        reverse(builder.begin(), builder.end());
        return string(builder.begin(), builder.end());
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<int> unique;
        for (auto binstr : nums) {
            auto value = binaryStringToInt(binstr);
            unique.insert(value);
        }

        for (int i = 0; i < (1 << (n + 1)); ++i) {
            if (unique.find(i) == unique.end()) {
                return intToBinaryString(i, n);
                
            }
        }

        return "";
    }
};

int main() {
    Solution solution;
    vector<string> nums = {"01", "10"};
    string result = solution.findDifferentBinaryString(nums);
    cout << result << endl;
    return 0;
}
