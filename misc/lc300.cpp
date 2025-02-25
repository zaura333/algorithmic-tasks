// 300. Longest Increasing Subsequence

#include <vector>

using std::vector;
using std::max;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int* dpLIS = new int[n];

        for (int i = 0; i < n; i++) {
            dpLIS[i] = 1;
        }

        int LIS = 1;

        for (int i = n-2; i >= 0; i--) {
            for (int j = i+1; j < n; j++) {
                if (nums[i] < nums[j]) {
                    dpLIS[i] = max(dpLIS[i], 1 + dpLIS[j]);
                    LIS = max(LIS, dpLIS[i]);
                }
            }
        }

        delete[] dpLIS;
        return LIS;
    }
};
