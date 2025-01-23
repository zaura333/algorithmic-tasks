// 1267. Count Servers that Communicate

#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        unordered_map<int, int> rowsWithServers;
        unordered_map<int, int> columnsWithServers;
        set<pair<int, int>> servers;

        int rows = grid.size();
        int columns = grid[0].size();

        int count = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (grid[i][j] == 0) continue;
                rowsWithServers[i]++;
                columnsWithServers[j]++;

                pair<int, int> server = {i, j};
                servers.insert(server);
            }
        }

        for (auto& server : servers) {
            if (rowsWithServers[server.first] >= 2
            || columnsWithServers[server.second] >=2) {
                count++;
            }
        }

        return count;
    }
};
