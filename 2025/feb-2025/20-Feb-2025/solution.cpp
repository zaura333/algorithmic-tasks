// 1260. Shift 2D Grid
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> shifted = grid;
        vector<vector<int>> currShifted = shifted;
        int m = grid.size();
        if (!m) return grid;

        int n = grid[0].size();

        if (n*m == k) return grid;

        for (int l = 0; l < k; l++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    int curr = currShifted[i][j];
                    if (j < n - 1) {
                        shifted[i][j+1] = curr;
                    } else if (i < m - 1) {
                        shifted[i+1][0] = curr;
                    } else {
                        shifted[0][0] = curr;
                    }
                }
            }
            currShifted = shifted;
        }

        return shifted;
    }
};
