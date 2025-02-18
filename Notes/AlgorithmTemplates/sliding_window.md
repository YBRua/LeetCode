# Sliding Windows

> [Reference](https://leetcode.com/problems/frequency-of-the-most-frequent-element/discuss/1175088/C%2B%2B-Maximum-Sliding-Window-Cheatsheet-Template!)

## Shrinking Sliding Window

- The window is marked by two pointers `i` and `j`, with length `j - i + 1`
- We want to keep the window valid (by maintaining a certain `state`) and track its maximum valid length
  - We extend `j`
  - If the window becomes invalid, we shrink the window by increasing `i` until it is valid again

```cpp
vector<int> arr;
int i = 0; j = 0; max_val = 0;

while (j < arr.size()) {
    // CODE: Update state using j (extending the window)
    while (invalid()) {
        // CODE: Update state using i (shrinking the window)
        ++i;
    }
    max_val = max(max_val, j - i + 1);
    ++j;
}

int res = max_val;
```

### Examples

- [1838. Frequency of the Most Frequent Element](./../../1838.FrequencyOfTheMostFrequentElement/Freq.cpp)

## Non-Shrinking Sliding Window

- The window is marked by two pointers `i` and `j`
- We are only interested in the **maximum possible length** of the window
  - When the constraint is violated, since we have found at least one longest window, we do not shrink the window, but instead *shift it right by one unit* 
  - The window **may become invalid**, but this does not matter, because we can ensure that *at least a valid window with current maximum length exists*.
  - The maximum possible length only needs to be updated when the window is valid

```cpp
vector<int> arr;
int i = 0, j = 0;

while (j < arr.size()) {
    // CODE: Update state using j (extending the window)
    if (invalid()) {
        // CODE: Update state using i (shifting the window)
        ++i;
    }
    ++j; // NOTE: The window [i, j) can be invalid, but it does not matter
}

int res = j - i;
```

### Examples

- [424. Longest Repeating Character Replacement](./../../424.LongestRepeatingCharacterReplacement/LongestRepeatingChar.cpp)
