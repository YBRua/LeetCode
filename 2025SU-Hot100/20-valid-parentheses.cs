using System;
using System.Collections.Generic;

namespace Hot100SU2025 {
    public class Solution20 {
        // 20-valid-parentheses
        public bool IsValid(string s) {
            var tonyStack = new Stack<char>();
            var matcher = new Dictionary<char, char>() { { ')', '(' }, { ']', '[' }, { '}', '{' } };

            foreach (var ch in s) {
                if (ch == '(' || ch == '[' || ch == '{') {
                    tonyStack.Push(ch);
                } else {
                    if (tonyStack.Count == 0) {
                        return false;
                    }
                    if (tonyStack.Peek() != matcher[ch]) {
                        return false;
                    }
                    tonyStack.Pop();
                }
            }

            if (tonyStack.Count > 0) {
                return false;
            }
            return true;
        }
    }
}
