#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    void happyStringBuilderHelper(int n, string happyString, vector<string>& happyStrings) {
        if (happyString.size() == n) {
            happyStrings.push_back(happyString);
            return;
        }

        for (char c = 'a'; c <= 'c'; c++) {
            if (happyString.empty() || happyString.back() != c) {
                happyStringBuilderHelper(n, happyString + c, happyStrings);
            }
        }

        return;
    }

    void happyStringBuilder(int n, vector<string>& happyStrings) {
        string happyString = "";
        happyStringBuilderHelper(n, happyString, happyStrings);
        return;
    }

    string getHappyString(int n, int k) {
        vector<string> happyStrings;
        happyStringBuilder(n, happyStrings);
        if (k > happyStrings.size()) {
            return "";
        }
        return happyStrings[k - 1];
    }
};