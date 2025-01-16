// 2425. Bitwise XOR of All Pairings
// Optimized solution

#include <vector>
using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1 = 0;
        int xor2 = 0;
        int size1 = nums1.size();
        int size2 = nums2.size();

        if (size1 % 2 == 0 && size2 % 2 == 0) {
            return 0;
        }

        if (size2 % 2 == 1) {
            for (int i = 0; i < size1; i++) {
                xor1 = xor1 ^ nums1[i];
            }
        }

        if (size1 % 2 == 0) {
            return xor1;
        }
        
        if (size1 % 2 == 1) {
            for (int i = 0; i < size2; i++) {
                xor2 = xor2 ^ nums2[i];
            }
        }

        if (size2 % 2 == 0) {
            return xor2;
        }

        return xor1 ^ xor2;
    }
};
