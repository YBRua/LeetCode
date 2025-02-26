#include <vector>
using namespace std;

class Solution {
   public:
    int numOfSubarrays(vector<int>& arr) {
        const int MODULO = 1000000007;
        int cnt = 0;

        for (int start = 0; start < arr.size(); ++start) {
            bool is_odd_sum = arr[start] % 2 != 0;
            if (is_odd_sum) {
                cnt = (cnt + 1) % MODULO;
            }

            for (int len = 2; start + len - 1 < arr.size(); ++len) {
                int new_val = arr[start + len - 1];
                bool is_new_val_odd = new_val % 2 != 0;
                if (is_new_val_odd) {
                    is_odd_sum = !is_odd_sum;
                }
                if (is_odd_sum) {
                    cnt = (cnt + 1) % MODULO;
                }
            }
        }

        return cnt;
    }
};
