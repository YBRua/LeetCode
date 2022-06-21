/**
 * A string is "valid" if it can be transformed from empty string
 * by inserting "abc" at any position of it for any times
 * Determines if a string is "valid".
 */
#include <stack>
#include <iostream>
#include <string>

using namespace std;


bool isValid(string s) {
    stack<char> stk;
    for (auto ch : s) {
        if (ch != 'c') {
            stk.emplace(ch);
        } else {
            if (stk.size() < 2) {
                return false;
            } else {
                char should_be_b = stk.top(); stk.pop();
                char should_be_a = stk.top(); stk.pop();
                if (should_be_b != 'b' || should_be_a != 'a') {
                    return false;
                }
            }
        }
    }

    if (stk.size()) {
        return false;
    }
    return true;
}


int main() {
    string s = "ababcc";
    cout << isValid(s) << endl;
}
