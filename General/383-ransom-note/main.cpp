// 383-ransom-note
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mag_budget;
        for (char ch : magazine) {
            ++mag_budget[ch];
        }

        unordered_map<char, int> requirements;
        for (char ch : ransomNote) {
            ++requirements[ch];
        }

        for (auto [key, value] : requirements) {
            if (mag_budget.find(key) == mag_budget.end() || mag_budget.at(key) < value) {
                return false;
            }
        }

        return true;
    }
};
