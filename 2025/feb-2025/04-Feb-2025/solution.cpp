// 1800. Maximum Ascending Subarray Sum

#include <vector>

using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = nums[0];
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            int currSum = nums[i];

            while (i < n - 1 && nums[i] < nums[i+1]) {
                currSum += nums[i+1];
                i++;
            }

            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};
