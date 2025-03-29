using System;
using System.Collections.Generic;
using System.Linq;


namespace Hot100SU2025 {
    // 238-product-of-array-except-self
    public class Solution238 {
        public int[] ProductExceptSelf(int[] nums) {
            int n = nums.Length;
            int[] leftProd = new int[n];
            int[] rightProd = new int[n];

            int prod = 1;
            for (int i = 0; i < n; ++i) {
                leftProd[i] = prod;
                prod *= nums[i];
            }

            prod = 1;
            for (int i = n - 1; i >= 0; --i) {
                rightProd[i] = prod;
                prod *= nums[i];
            }

            int[] res = new int[n];
            for (int i = 0; i < n; ++i) {
                res[i] = leftProd[i] * rightProd[i];
            }

            return res;
        }
    }
}