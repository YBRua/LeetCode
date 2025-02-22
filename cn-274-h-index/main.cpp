#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int h_index = 0;
        for (int i = 0; i < citations.size(); i++) {
            int x = citations.size() - i;
            h_index = max(h_index, min(x, citations[i]));
        }

        return h_index;
    }
};