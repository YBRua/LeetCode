#include <vector>

using namespace std;

class Solution {
public:
    int k_;
    int n_;
    vector<vector<int>> combine(int n, int k) {
        this->k_ = k;
        this->n_ = n;
        vector<vector<int>> res;
        vector<int> current;
        _combine(res, current, 0);

        return res;
    }
    
    void _combine(vector<vector<int>>& res, vector<int>& current, int start) {
        if (current.size() == this->k_) {
            res.push_back(current);
            return;
        }
        for (int i = start + 1; i <= this->n_; ++i) {
            current.push_back(i);
            _combine(res, current, i);
            current.pop_back();
        }
        return;
    }
};
