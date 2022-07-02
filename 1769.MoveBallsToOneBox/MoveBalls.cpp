#include <cmath>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
   public:
    // vector<int> minOperations(string boxes) {
    //     // O(n^2) Sol, brutal force
    //     unordered_set<int> has_ball;
    //     vector<int> results(boxes.length(), 0);
    //     for (int i = 0; i < boxes.length(); ++i) {
    //         if (boxes[i] == '1') has_ball.emplace(i);
    //     }
    //     for (int i = 0; i < boxes.length(); ++i) {
    //         int res = 0;
    //         for (auto idx : has_ball) {
    //             res += abs(idx - i);
    //         }
    //         results[i] = res;
    //     }
    //     return results;
    // }
    vector<int> minOperations(string boxes) {
        // DP, O(n)
        // dp[i]: moves needed to move all balls from [0:i] to i
        // dp[i] = dp[i-1] + cost * balls[i]
        // where balls[i] is the existing balls in [0:i]
        // note that this update only considers one direction (left to right)
        // we need an extra right-to-left scan to make the result correct
        vector<int> dp(boxes.length(), 0);
        int balls = 0, prev = 0;
        balls = boxes.front() == '1' ? 1 : 0;
        for (int i = 1; i < boxes.size(); ++i) {
            dp[i] += prev + 1 * balls;
            prev = prev + 1 * balls;
            balls += boxes[i] == '1' ? 1 : 0;
        }

        balls = 0, prev = 0;
        balls = boxes.back() == '1' ? 1 : 0;
        for (int i = boxes.size() - 1; i > 0; --i) {
            dp[i-1] += prev + 1 * balls;
            prev = prev + 1 * balls;
            balls += boxes[i-1] == '1' ? 1 : 0;
        }

        return dp;
    }
};
