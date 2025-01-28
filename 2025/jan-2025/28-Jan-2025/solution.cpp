// 2658. Maximum Number of Fish in a Grid

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        const int rows = grid.size();
        const int columns = grid[0].size();
        vector<vector<int>> tempGrid = grid;
        int maxFish = 0;

        const int dx[] = {1, -1, 0, 0};
        const int dy[] = {0, 0, 1, -1};

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (tempGrid[i][j] != 0) {
                    queue<pair<int, int>> q;
                    int currMax = 0;
                    q.push({i, j});

                    while (!q.empty()) {
                        pair<int, int> curr = q.front();
                        q.pop();

                        int l = curr.first;
                        int m = curr.second;

                        currMax += tempGrid[l][m];

                        for (int k = 0; k < 4; k++) {
                            if ((l + dx[k]) >= rows || (l + dx[k]) < 0) continue;
                            if ((m + dy[k]) >= columns || (m + dy[k]) < 0) continue;

                            if (tempGrid[l + dx[k]][m + dy[k]] != 0) {
                                q.push({l + dx[k], m + dy[k]});
                            }
                        }

                        tempGrid[l][m] = 0;
                    }

                    if (currMax > maxFish) {
                        maxFish = currMax;
                    }
                }
            }
        }

        return maxFish;
    }
};
