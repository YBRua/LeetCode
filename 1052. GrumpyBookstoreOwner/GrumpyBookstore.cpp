#include <vector>

using namespace std;


class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int total_customers = 0;
        int total_unsat = 0;
        int can_sat = 0;
        int max_can_sat = 0;

        for (int i = 0; i < customers.size(); ++i) {
            total_customers += customers[i];
            if (grumpy[i]) {
                total_unsat += customers[i];
                can_sat += customers[i] * grumpy[i];
            }
            if (i >= minutes) {
                can_sat -= customers[i - minutes] * grumpy[i - minutes];
            }
            max_can_sat = max(max_can_sat, can_sat);
        }
        return total_customers - total_unsat + max_can_sat;
    }
};
