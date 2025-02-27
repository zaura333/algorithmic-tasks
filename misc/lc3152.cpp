// 3152. Special Array II

#include <vector>

using std:: vector;

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> subarrays(n, 0);
        int subNumber = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i - 1] % 2 == nums[i] % 2) 
                subNumber++;

            subarrays[i] = subNumber;
        }

        vector<bool> answers;

        for (auto& q : queries) {
            bool special = subarrays[q[0]] == subarrays[q[1]];
            answers.push_back(special);
        }

        return answers;
    }
};
