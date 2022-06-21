#include <vector>
#include <iostream>

using namespace std;

int solver(vector<int>& nums)
{
    vector<pair<int, int>> pair_buffer;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] == 1)
        {
            int j = i;
            while (j < nums.size() && nums[j] == 1)
            {
                ++j;
            }
            pair_buffer.push_back(pair<int, int>(i, j - i));
            i = j;
        }
    }
    // start_idx, length
    if (pair_buffer.size() == 0)
    {
        // all zeros
        return 0;
    }
    if (pair_buffer.size() == 1)
    {
        if (pair_buffer[0].second == nums.size())
        {
            // all ones
            return nums.size() - 1;
        } else {
            return pair_buffer[0].second;
        }
    }

    int maxval = 0;

    for (int i = 1; i < pair_buffer.size(); ++i)
    {
        auto prev = pair_buffer[i - 1];
        auto current = pair_buffer[i];
        int prev_end_idx = prev.first + prev.second;
        if (prev_end_idx + 1 == current.first)
        {
            maxval = max(maxval, prev.second + current.second);
        } else {
            maxval = max(maxval, prev.second);
            maxval = max(maxval, current.second);
        }
    }
    return maxval;
}

int main() {
    std::vector<int> nums = {1, 0, 0, 0, 0};
    std::cout << solver(nums) << std::endl;

    return 0;
}
