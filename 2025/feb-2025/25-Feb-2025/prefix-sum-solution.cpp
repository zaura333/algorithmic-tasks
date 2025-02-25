// 1524. Number of Sub-arrays With Odd Sum

#include <vector>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();

        int prefixSum = 0, evenCount = 1, oddCount = 0, result = 0;

        for (int i = 0; i < n; i++) {
            prefixSum += arr[i];

            if (prefixSum % 2 == 0) {
                evenCount++;
                result += oddCount;
            } else {
                oddCount++;
                result += evenCount;
            }

            result %= MOD;
        }

        return result;
    }
};
