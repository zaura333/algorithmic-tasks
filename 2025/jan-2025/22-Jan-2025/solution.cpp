// 1765. Map of Highest Peak

#include <vector>
#include <map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>> heights = isWater;
        int rows = heights.size();
        int columns = heights[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (heights[i][j] == 0) {
                    heights[i][j] = -1;
                } else {
                    heights[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int i = curr.first;
            int j = curr.second;

            for (int k = 0; k < 4; k++) {
                if ((i + dx[k]) >= rows || (i + dx[k]) < 0) continue;
                if ((j + dy[k]) >= columns || (j + dy[k]) < 0) continue;

                if (heights[i + dx[k]][j + dy[k]] == -1) {
                    heights[i + dx[k]][j + dy[k]] = heights[i][j] + 1;
                    q.push({i + dx[k], j + dy[k]});
                }
            }
        }

        return heights;
    }
};
