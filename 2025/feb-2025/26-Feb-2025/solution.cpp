// 1749. Maximum Absolute Sum of Any Subarray - KADANE'S ALGORITHM - DP

#include <vector>

using std::vector, std::min, std::max;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> dpSum = nums;
        int maxSum = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            dpSum[i] = nums[i] > nums[i] + dpSum[i + 1]
            ? nums[i]
            : nums[i] + dpSum[i + 1];
            
            // cout << "\n" << dpSum[i];

            maxSum = max(abs(dpSum[i]), maxSum);
        }

        // cout << "\n-------MIN--------\n";

        dpSum = nums;
        int minSum = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            dpSum[i] = nums[i] < (nums[i] + dpSum[i + 1])
            ? nums[i]
            : nums[i] + dpSum[i + 1];
            
            // cout << "\n" << dpSum[i];

            minSum = min(dpSum[i], minSum);
        }

        return max(abs(maxSum), abs(minSum));
    }
};
