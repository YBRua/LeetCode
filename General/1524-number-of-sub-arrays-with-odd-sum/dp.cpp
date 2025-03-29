#include <vector>
using namespace std;

class Solution {
   public:
    int numOfSubarrays(vector<int>& arr) {
        const int MODULO = 1000000007;
        // number of even/odd arrs ending at i
        vector<int> dp_even(arr.size(), 0);
        vector<int> dp_odd(arr.size(), 0);

        if (arr[0] % 2 == 0) {
            dp_even[0] = 1;
        } else {
            dp_odd[0] = 1;
        }

        // if arr[i] is even
        //   dpeven[i] = dpeven[i - 1] + 1
        //   dpodd[i] = dpodd[i - 1]
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] % 2 == 0) {
                // even
                dp_even[i] = (dp_even[i - 1] + 1) % MODULO;
                dp_odd[i] = dp_odd[i - 1];
            } else {
                // odd
                dp_even[i] = dp_odd[i - 1];
                dp_odd[i] = (dp_even[i - 1] + 1) % MODULO;
            }
        }

        int cnt = 0;
        for (int odd_cnt : dp_odd) {
            cnt = (cnt + odd_cnt) % MODULO;
        }

        return cnt;
    }
};
