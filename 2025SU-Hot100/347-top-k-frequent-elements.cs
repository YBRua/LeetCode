using System;
using System.Collections.Generic;

namespace Hot100SU2025 {
    public class Solution347 {
        // 347-top-k-frequent-elements

        public class ElementFrequency(int element, int frequency) {
            public int element = element;
            public int frequency = frequency;
        }

        public int[] TopKFrequent(int[] nums, int k) {
            var counter = new Dictionary<int, int>();
            foreach (var num in nums) {
                counter[num] = counter.GetValueOrDefault(num, 0) + 1;
            }

            var pq = new PriorityQueue<ElementFrequency, int>();

            foreach (var item in counter) {
                var curr = new ElementFrequency(item.Key, item.Value);
                pq.Enqueue(curr, curr.frequency);
                if (pq.Count > k) {
                    pq.Dequeue();
                }
            }

            int[] res = new int[k];
            for (int i = 0; i < k; ++i) {
                res[i] = pq.Dequeue().element;
            }

            return res;
        }
    }
}
