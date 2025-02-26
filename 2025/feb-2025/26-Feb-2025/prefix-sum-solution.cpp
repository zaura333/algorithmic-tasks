// 1749. Maximum Absolute Sum of Any Subarray - PREFIX SUM

#include <vector>

using std::vector, std::min, std:: max;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int prefixSum = nums[0];
        int maxSum = nums[0];
        int minPrefix = min(nums[0], 0);

        for (int i = 1; i < n; i++) {
            prefixSum += nums[i];
            maxSum = max(prefixSum - minPrefix, maxSum);
            minPrefix = min(prefixSum, minPrefix);
            
            // cout << "\n" << prefixSum << " minPrefix: " << minPrefix << " currSum: " << maxSum;
        }

        // cout << "\n-------MIN--------\n";

        prefixSum = nums[0];
        int minSum = nums[0];
        int maxPrefix = max(nums[0], 0);

        for (int i = 1; i < n; i++) {
            prefixSum += nums[i];
            minSum = min(prefixSum - maxPrefix, minSum);
            maxPrefix = max(prefixSum, maxPrefix);
            
            // cout << "\n" << prefixSum << " maxPrefix: " << maxPrefix << " currSum: " << minSum;
        }

        return max(abs(maxSum), abs(minSum));
    }
};
