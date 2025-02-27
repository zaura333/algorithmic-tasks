// 873. Length of Longest Fibonacci Subsequence

#include <vector>
#include <unordered_map>

using std::vector, std::unordered_map, std::max;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int longestFib = 0;
        unordered_map<int, int> valIndex;

        for (int i = 0; i < n; i++) {
            valIndex[arr[i]] = i;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[i][j] == 0) dp[i][j] = 2;
                int nextFib = arr[i] - arr[j];

                if (valIndex.contains(nextFib) && valIndex[nextFib] < j) {
                    dp[j][valIndex[nextFib]] = dp[i][j] + 1;
                }

                

                longestFib = max(dp[i][j], longestFib);
            }
        }

        if (longestFib < 3) return 0;

        return longestFib;
    }
};
