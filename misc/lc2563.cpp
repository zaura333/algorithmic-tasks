// 2563. Count the Number of Fair Pairs

#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        return pairsInRange(sorted, upper + 1) - pairsInRange(sorted, lower);
    }

private:
    long long pairsInRange(vector<int>& nums, int boundary) {
        int left = 0, right = nums.size() - 1;
        long long pairsCount = 0;

        while (left < right) {
            int sum = nums[left] + nums[right];

            if (sum < boundary) {
                pairsCount += (right - left);
                left++;
            } else {
                right--;
            }
        }

        return pairsCount;
    }
};
