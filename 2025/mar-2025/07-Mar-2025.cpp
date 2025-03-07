// 2523. Closest Prime Numbers in Range

#include <vector>

using std::vector;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> result(2, -1);
        int currDifference = INT_MAX;

        vector<bool> primes = markNPrimes(right);

        for (int i = right; i > left; i--) {
            if (!primes[i]) continue;
            
            for (int j = i - 1; j >= left; j--) {
                if (!primes[j]) continue;

                if (i - j <= currDifference) {
                    result[0] = j;
                    result[1] = i;
                    currDifference = i - j;
                }
                break;
            }
        }

        return result;
    }

    vector<bool> markNPrimes(int n) {
        vector<bool> primes(n + 1, true);

        for (int p = 2; p * p <= n; p++) {
            if (primes[p]) {
                for (int i = p * p; i <= n; i += p) {
                    primes[i] = false;
                }
            }
        }

        primes[0] = false;
        primes[1] = false;

        return primes;
    }
};
