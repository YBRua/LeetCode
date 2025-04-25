using System;
using System.Collections.Generic;
using System.Text;

namespace Hot100SU2025 {
    public class Solution394 {
        // 394-decode-string
        public string DecodeString(string s) {
            int nRepeats = 0;
            var curr = new StringBuilder();

            var stack = new Stack<(StringBuilder, int)>();

            for (int i = 0; i < s.Length; ++i) {
                var currChar = s[i];
                if (char.IsAsciiLetter(currChar)) {
                    curr.Append(currChar);
                } else if (char.IsDigit(currChar)) {
                    nRepeats = 10 * nRepeats + (currChar - '0');
                } else if (currChar == '[') {
                    stack.Push((curr, nRepeats));
                    curr = new StringBuilder();
                    nRepeats = 0;
                } else if (currChar == ']') {
                    var (prevBuilder, prevRepeats) = stack.Pop();
                    for (int j = 0; j < prevRepeats; ++j) {
                        prevBuilder.Append(curr);
                    }
                    curr = prevBuilder;
                    nRepeats = 0;
                }
            }

            return curr.ToString();
        }
    }
}
