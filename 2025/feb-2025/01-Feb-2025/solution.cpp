// 3151. Special Array I

#include <vector>

using namespace std;

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return true;

        bool even = nums[0] % 2 == 0;

        for (int i = 1; i < n; i++) {
            even = !even;
            if ((even && nums[i] % 2 != 0) || (!even && nums[i] % 2 == 0)) {
                return false;
            }
        }

        return true;
    }
};
