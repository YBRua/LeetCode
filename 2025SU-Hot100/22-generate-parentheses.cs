// 22-generate-parentheses
using System;
using System.Collections.Generic;
using System.Text;

namespace Hot100SU2025 {
    public class Solution22 {
        public void Generator(List<string> res, int n, StringBuilder curr, int n_begins, int n_openings) {
            if (curr.Length == 2 * n) {
                res.Add(curr.ToString());
                return;
            }

            if (n_begins < n) {
                // can add '('
                curr.Append('(');
                Generator(res, n, curr, n_begins + 1, n_openings + 1);
                curr.Length--;
            }
            if (n_openings > 0) {
                // can add ')'
                curr.Append(')');
                Generator(res, n, curr, n_begins, n_openings - 1);
                curr.Length--;
            }
        }

        public IList<string> GenerateParenthesis(int n) {
            List<string> res = [];
            Generator(res, n, new StringBuilder(), 0, 0);
            return res;
        }
    }
}
