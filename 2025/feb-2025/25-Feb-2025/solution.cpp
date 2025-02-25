// 1524. Number of Sub-arrays With Odd Sum

#include <vector>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();

        vector<int> convertedArray = arr;
        for (auto& num : convertedArray) {
            num %= 2;
        }

        vector<int> evenSums(n, 0);
        vector<int> oddSums(n, 0);

        if (convertedArray[n-1] % 2 == 0) {
            evenSums[n-1] = 1;
        } else {
            oddSums[n-1] = 1;
        }

        for (int i = n - 2; i >= 0; i--) {
            if (convertedArray[i] == 1) {
                oddSums[i] = (evenSums[i+1] + 1) % MOD;
                evenSums[i] = oddSums[i+1];
            } else {
                evenSums[i] = (evenSums[i+1] + 1) % MOD;
                oddSums[i] = oddSums[i+1];
            }
        }

        int oddSumsCount = 0;
        for (auto& sum : oddSums) {
            oddSumsCount += sum;
            oddSumsCount %= MOD;
        }

        return oddSumsCount;
    }
};
