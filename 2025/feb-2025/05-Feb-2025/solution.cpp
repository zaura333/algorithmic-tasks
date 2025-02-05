// 1790. Check if One String Swap Can Make Strings Equal

#include <string>

using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int length = s1.size();
        int toSwap[2];
        int different = 0;

        for (int i = 0; i < length; i++) {
            if (s1[i] != s2[i]) {
                different++;
                if (different > 2) return false;
                toSwap[different-1] = i;
            }
        }

        if (s1[toSwap[0]] != s2[toSwap[1]] || s1[toSwap[1]] != s2[toSwap[0]]) {
            return false;
        }

        return true;
    }
};
