// 3208. Alternating Groups II

#include <vector>

using std::vector;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int altNum = 0;
        int currAlt = 0;
        bool isAlt = true;
        int j = 0;
        int n = colors.size();

        for (int i = 0; i < n; i++) {
            while (j < i + k - 1) {
                j++;
                if (colors[j % n] == colors[(j - 1) % n]) {
                    i = j;
                }
                if (i >= n) {
                    isAlt = false;
                    break;
                }
            }

            // cout << "\ni: " << i << " j: " << j << " isAlt: " << isAlt;

            if  (isAlt) {
                altNum++;
            }
        }

        return altNum;
    }
};
