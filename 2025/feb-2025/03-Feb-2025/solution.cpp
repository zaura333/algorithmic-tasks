// 3105. Longest Strictly Increasing or Strictly Decreasing Subarray

#include <vector>

using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxLength = 1;
        int currLength = 1;

        int i = 0;
        while (i < nums.size() - 1 && nums[i] == nums[i+1]) {
            i++;
        }

        if (i == nums.size() - 1) return maxLength;

        bool increasing = nums[i] < nums[i+1];

        while (i < nums.size() - 1) {
            if (nums[i] == nums[i+1]) {
                maxLength = max(maxLength, currLength);
                currLength = 1;

                if (i < nums.size() - 2){
                    increasing = nums[i+1] < nums[i+2];
                }
            } else if (increasing && nums[i] < nums[i+1]) {
                currLength++;
            } else if (!increasing && nums[i] > nums[i+1]) {
                currLength++;
            } else {
                maxLength = max(maxLength, currLength);
                increasing = !increasing;
                currLength = 1;
                continue;
            } 

            i++;
        }

        maxLength = max(maxLength, currLength);

        return maxLength;
    }
};
