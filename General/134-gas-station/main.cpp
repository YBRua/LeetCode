#include <vector>
using namespace std;

class Solution {
   public:
    // if we cannot reach station y+1 starting from x
    // then we cannot reach y+1 from any station z in [x, y]
    // because from x to z we would have accumulated some remaining gas
    // therefore we only need to start checking from y + 1
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, n = gas.size();
        while (start < n) {
            int tot_gas = 0, tot_cost = 0;
            int dist = 0;
            while (dist < n) {
                int curr = (start + dist) % n;
                tot_gas += gas[curr];
                tot_cost += cost[curr];
                if (tot_cost > tot_gas) {
                    break;
                }
                dist++;
            }

            if (dist == n) {
                return start;
            }
            start = start + dist + 1;
        }

        return -1;
    }
};