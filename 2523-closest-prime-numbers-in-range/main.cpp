// 2523-closest-prime-numbers-in-range
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> _markPrimesUpTo(int n) {
        // Sieve of Eratosthenes
        // Starting from 2 and iteratively mark multiples of each prime as non-prime
        vector<int> primes(n + 1, 1);
        primes[0] = primes[1] = 0;
        for (int i = 2; i * i <= n; i++) {
            if (primes[i]) {
                for (int j = i * i; j <= n; j += i) {
                    primes[j] = 0;
                }
            }
        }
        return primes;
    }

    vector<int> closestPrimes(int left, int right) {
        auto primes = _markPrimesUpTo(right);

        // collect primes between [left, right]
        vector<int> primes_in_range;
        for (int i = left; i <= right; i++) {
            if (primes[i]) {
                primes_in_range.push_back(i);
            }
        }

        // find the closest pair of primes
        int min_diff = INT_MAX;
        vector<int> closest_pair;
        for (int i = 1; i < primes_in_range.size(); i++) {
            int diff = primes_in_range[i] - primes_in_range[i - 1];
            if (diff < min_diff) {
                min_diff = diff;
                closest_pair = {primes_in_range[i - 1], primes_in_range[i]};
            }
        }

        if (min_diff == INT_MAX) {
            return {-1, -1};
        }
        return closest_pair;
    }
};
