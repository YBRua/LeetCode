using System.Collections.Generic;


namespace Hot100SU2025 {
    // 76-minimum-window-substring
    public class Solution76 {
        public string MinWindow(string s, string t) {
            Dictionary<char, int> counter = new();

            foreach (char ch in t) {
                counter[ch] = counter.GetValueOrDefault(ch, 0) + 1;
            }

            // counts the number of characters in t that are not in window
            int nDiffs = counter.Count;
            int ansL = 0, ansR = s.Length;
            int lp = 0, rp = 0;

            while (rp < s.Length) {
                char currChar = s[rp];
                int value = 0;
                if (counter.TryGetValue(currChar, out value)) {
                    counter[currChar] = --value;

                    // if counter value is 0, 
                    // the window contains the desired number of char
                    if (value == 0) {
                        nDiffs--;
                    }
                }

                while (nDiffs == 0) {
                    if (rp - lp < ansR - ansL) {
                        ansL = lp;
                        ansR = rp;
                    }

                    char leftChar = s[lp];

                    if (counter.TryGetValue(leftChar, out value)) {
                        counter[leftChar] = ++value;

                        if (value > 0) {
                            nDiffs++;
                        }
                    }

                    lp++;
                }

                rp++;
            }

            return ansR == s.Length ? "" : s.Substring(ansL, ansR - ansL + 1);
        }
    }
}