
#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
   public:
    bool sat(unordered_map<char, int>& target_counter, unordered_map<char, int>& running_counter) {
        for (const auto [key, value] : target_counter) {
            if (value > running_counter[key]) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        unordered_map<char, int> target_counter;
        for (auto ch : t) {
            target_counter[ch] += 1;
        }

        int l = 0, r = 0;
        int min_len = numeric_limits<int>::max();
        int ans_l = -1, ans_r = -1;

        unordered_map<char, int> running_counter;
        while (r < s.size()) {
            if (target_counter.find(s[r]) != target_counter.end()) {
                running_counter[s[r]]++;
            }

            while (sat(target_counter, running_counter) && l <= r) {
                if (r - l + 1 < min_len) {
                    min_len = r - l + 1;
                    ans_l = l;
                    ans_r = r;
                }
                if (target_counter.find(s[l]) != target_counter.end()) {
                    running_counter[s[l]]--;
                }
                l++;
            }

            r++;
        }

        if (ans_l != -1) {
            return s.substr(ans_l, ans_r - ans_l + 1);
        } else {
            return "";
        }
    }
};

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << Solution().minWindow(s, t) << endl;

    return 0;
}
