#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        vector<int> res;
        sort(arr.begin(), arr.end());
        int median = arr[(arr.size() - 1) / 2];
        int i = 0, j = arr.size() - 1;
        int k_ = 0;
        while (k_ < k) {
            // strongest numbers are always at the beginning or the end
            // of the sorted array
            if (abs(arr[i] - median) > abs(arr[j] - median)) {
                res.push_back(arr[i]);
                i++;
                k_++;
            } else {
                res.push_back(arr[j]);
                j--;
                k_++;
            }
        }

        return res;
    }
};
