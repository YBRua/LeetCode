#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    class ElementFrequency {
       public:
        int element;
        int frequency;

        ElementFrequency(int elem, int freq) : element(elem), frequency(freq) {}

        bool operator<(ElementFrequency other) const { return this->frequency > other.frequency; }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        for (auto num : nums) {
            counter[num]++;
        }

        priority_queue<ElementFrequency> pq;

        for (auto item : counter) {
            pq.emplace(ElementFrequency(item.first, item.second));
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> res;
        for (int i = 0; i < k; ++i) {
            auto curr = pq.top();
            pq.pop();
            res.emplace_back(curr.element);
        }

        return res;
    }
};