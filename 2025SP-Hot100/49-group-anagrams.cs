using System.Collections.Generic;
using System.Text;

namespace Hot100SU2025 {
    public class Solution49 {
        // 49-group-anagrams
        public IList<IList<string>> GroupAnagrams(string[] strs) {
            List<List<string>> res = new();
            Dictionary<string, List<string>> dict = new();

            foreach (string str in strs) {
                var cnt = new StringBuilder("00000000000000000000000000000000");
                foreach (char ch in str) {
                    cnt[ch - 'a']++;
                }
                string key = cnt.ToString();
                if (!dict.ContainsKey(key)) {
                    dict[key] = new List<string>();
                }
                dict[key].Add(str);
            }

            foreach (var pair in dict) {
                res.Add(pair.Value);
            }

            return res.ToArray();
        }
    }
}
