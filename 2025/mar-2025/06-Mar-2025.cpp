// 2965. Find Missing and Repeated Values - two solutions

#include <vector>

using std::vector;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int nSqrd = rows * rows;
        vector<int> vals(nSqrd, 0);
        vector<int> result(2, -1);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                int curr = grid[i][j];
                vals[curr - 1] += 1;

                if (vals[curr - 1] == 2) result[0] = curr;
            }
        }

        for (int k = 1; k <= nSqrd; k++) {
            if (vals[k - 1] == 0) result[1] = k;
        }

        return result;
    }

    // second solution using math and sum of a series
    vector<int> findMissingAndRepeatedValuesMath(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int nSqrd = rows * rows;
        int sum = 0;
        vector<int> vals(nSqrd, 0);
        vector<int> result(2, -1);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                int curr = grid[i][j];

                if (vals[curr - 1] == 1) {
                    result[0] = curr;
                    continue;
                }

                vals[curr - 1] += 1;
                sum += curr;
            }
        }

        float totalSum = ((1 + float(nSqrd)) / 2) * float(nSqrd);

        result[1] = int(ceil(totalSum)) - sum;

        return result;
    }
};