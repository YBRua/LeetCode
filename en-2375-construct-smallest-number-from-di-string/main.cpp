#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
   public:
    string smallestNumber(string pattern) {
        stack<int> stack;
        string res = "";

        int val = 1;
        int idx = 0;

        stack.push(val);
        for (idx = 0; idx < pattern.size(); idx++) {
            if (pattern[idx] == 'I') {
                while (!stack.empty()) {
                    res += to_string(stack.top());
                    stack.pop();
                }
            }
            stack.push(++val);
        }

        while (!stack.empty()) {
            res += to_string(stack.top());
            stack.pop();
        }

        return res;
    }
};

int main() {
    Solution solution;
    string pattern = "IIIDIDDD";
    string res = solution.smallestNumber(pattern);

    cout << res << endl;

    return 0;
}
