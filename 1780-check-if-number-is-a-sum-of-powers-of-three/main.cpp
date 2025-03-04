#include <vector>
using namespace std;

class Solution {
   public:
    bool checkPowersOfThree(int n) {
        vector<int> bits(21);  // up to 3**20, should be more than enough

        int bit_ptr = 0;
        while (n > 0) {
            bits[bit_ptr] = n % 3;
            bit_ptr++;
            n /= 3;
        }

        for (auto bit : bits) {
            if (bit == 2) {
                return false;
            }
        }

        return true;
    }
};
