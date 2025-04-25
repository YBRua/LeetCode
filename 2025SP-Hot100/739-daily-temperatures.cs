using System;
using System.Collections.Generic;
using System.Linq;

namespace Hot100SU2025 {
    public class Solution739 {
        // 739-daily-temperatures
        public int[] DailyTemperatures(int[] temperatures) {
            var res = Enumerable.Repeat(0, temperatures.Length).ToArray();
            var stack = new Stack<int>();

            for (int i = 0; i < temperatures.Length; ++i) {
                if (stack.Count > 0) {
                    while (stack.Count > 0) {
                        var prevIndex = stack.Peek();
                        if (temperatures[prevIndex] < temperatures[i]) {
                            res[prevIndex] = i - prevIndex;
                            stack.Pop();
                        } else {
                            break;
                        }
                    }
                }
                stack.Push(i);
            }

            return res;
        }
    }
}
