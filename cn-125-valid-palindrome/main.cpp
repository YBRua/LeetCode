#include <cctype>
#include <string>
#include <iostream>

using namespace std;

class Solution {
   public:
    char safe_tolower(char ch) { return static_cast<char>(std::tolower(static_cast<unsigned char>(ch))); }
    bool isPalindrome(string s) {
        int begin = 0, end = s.size() - 1;
        while (begin < end) {
            while (begin < end && !isalnum(s[begin])) {
                begin++;
            }
            while (begin < end && !isalnum(s[end])) {
                end--;
            }

            if (begin >= end) {
                return true;
            }

            if (safe_tolower(s[begin]) != safe_tolower(s[end])) {
                return false;
            }
            begin++;
            end--;
        }

        return true;
    }
};


int main() {
    string test = "A man, a plan, a canal: Panama";
    Solution solver;
    cout << solver.isPalindrome(test);
}