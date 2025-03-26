// 2033. Minimum Operations to Make a Uni-Value Grid

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            vector<int> nums;
            int remainder = grid[0][0] % x;
    
            for (int i = 0; i < grid.size(); i++) {
                for (int j = 0; j < grid[0].size(); j++) {
                    int num = grid[i][j];
    
                    if (num % x != remainder) return -1;
    
                    nums.push_back(num);
                }
            }
    
            nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
    
            int median = nums[nums.size() / 2];
            int operationsNum = 0;
    
            for (int n : nums) {
                operationsNum += abs((n - median) / x);
            }
    
            return operationsNum;
        }
    };
    