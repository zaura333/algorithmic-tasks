// 1752. Check if Array Is Sorted and Rotated

#include <vector>

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        if (n < 2) return true;
        
        int minI = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minI]) {
                minI = i;
            }
        }

        if (minI == 0) {
            int j = n - 1;
            while (nums[j] == nums[0] && j > 1) {
                minI = j;
                j--;
            }

        }

        for (int i = minI; i < (minI + n - 1); i++) {
            int currI = i % n;
            int nextI = (i+1) % n;
            if (nums[currI] > nums[nextI]) {
                return false;
            }
        }

        return true;
    }
};
