// 2579. Count Total Number of Colored Cells

class Solution {
public:
    long long coloredCells(int n) {
        long long curr = 1LL;
        long long nextLvl = 4LL;

        for (int i = 1; i < n; i++) {
            curr += nextLvl;
            nextLvl += 4;
        }

        return curr;
    }
};
