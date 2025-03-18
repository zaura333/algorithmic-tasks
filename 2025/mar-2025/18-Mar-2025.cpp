// 2401. Longest Nice Subarray

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int maxLength = 0;
        int n = nums.size();
        int start = 0;
        int usedBits = 0;

        for (int end = 0; end < n; ++end) {
            while (usedBits & nums[end]) {
                usedBits ^= nums[start];
                start++;
            }
            maxLength = max(maxLength, end - start + 1);
            
            usedBits |= nums[end];
        }

        return maxLength;
    }
};
