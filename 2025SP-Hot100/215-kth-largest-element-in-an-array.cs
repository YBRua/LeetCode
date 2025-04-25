using System;
using System.Collections.Generic;
using System.Linq;


namespace Hot100SU2025 {
    // 215-kth-largest-element-in-an-array
    // here we use an optimized version of partitioning,
    // consider [1] * 100,
    // ordinary partitioning will result in idx = 0 and all elements are pushed to the right half
    // which could be inefficient if we were to find the 100th largest element
    public class Solution215 {
        public int Split(int[] nums, int left, int right) {
            int pivot = nums[left];
            int i = left + 1, j = right;
            while (i < j) {
                while (i < j && nums[j] > pivot) {
                    j--;
                }
                while (i < j && nums[i] < pivot) {
                    i++;
                }

                // performs swap and update even if nums[left] == nums[right] == pivot
                // so that duplicated pivots are evenly distributed
                if (i < j) {
                    (nums[i], nums[j]) = (nums[j], nums[i]);
                    i++;
                    j--;
                }
            }

            nums[j] = pivot;
            return j;
        }

        public int QuickSelect(int[] nums, int k, int left, int right) {
            int index = Split(nums, left, right);
            if (index == k) {
                return nums[index];
            } else if (index < k) {
                return QuickSelect(nums, k, index + 1, right);
            } else {
                return QuickSelect(nums, k, left, index - 1);
            }
        }
        public int FindKthLargest(int[] nums, int k) {
            return QuickSelect(nums, nums.Length - k, 0, nums.Length - 1);
        }
    }
}