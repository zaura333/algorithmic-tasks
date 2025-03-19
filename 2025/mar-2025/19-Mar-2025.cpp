// 3191. Minimum Operations to Make Binary Array Elements Equal to One I

#include <vector>

using std::vector;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> flippingNums = nums;
        int flips = 0;

        for (int i = 0; i < n - 2; i++) {
            if (flippingNums[i] == 0) {
                flippingNums[i] ^= 1;
                flippingNums[i + 1] ^= 1;
                flippingNums[i + 2] ^= 1;
                flips++;
            }
        }

        if (flippingNums[n - 1] == 0 || flippingNums[n - 2] == 0) {
            return -1;
        }

        return flips;
    }
};
