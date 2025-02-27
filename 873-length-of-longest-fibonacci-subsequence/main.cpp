#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int lenLongestFibSubseq(vector<int>& arr) {
        // length of fib subseq ending at res[i][j];
        vector<vector<int>> res(arr.size(), vector<int>(arr.size()));

        int max_length = 0;
        for (int i = 2; i < arr.size(); ++i) {
            int low = 0, high = i - 1;
            while (low < high) {
                if (arr[low] + arr[high] == arr[i]) {
                    res[high][i] = res[low][high] + 1;
                    max_length = max(max_length, res[high][i]);
                    low++;
                    high--;
                } else if (arr[low] + arr[high] > arr[i]) {
                    high--;
                } else {
                    low++;
                }
            }
        }

        return max_length == 0 ? 0 : max_length + 2;
    }
};

int main() {
    vector<int> input{1, 2, 3, 4, 5, 6, 7, 8};
    cout << Solution().lenLongestFibSubseq(input);

    return 0;
}