using System.Collections.Generic;

public class Solution {
    private Dictionary<char, int> _counter;
    private void _tryInc(char c) {
        if (!_counter.ContainsKey(c)) {
            _counter.Add(c, 0);
        }
        _counter[c] += 1;
    }
    private void _tryDec(char c) {
        _counter[c] -= 1;
    }
    public int LengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        _counter = new Dictionary<char, int>();
        int maxLen = 0;
        while (right < s.Length) {
            _tryInc(s[right]);
            while (_counter[s[right]] > 1) {
                _tryDec(s[left++]);
            }
            maxLen = System.Math.Max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
}
