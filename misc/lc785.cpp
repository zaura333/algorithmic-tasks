// 785. Is Graph Bipartite?

#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int* sets = new int[n];

        for (int i = 0; i < n; i++) {
            sets[i] = 0;
        }

        sets[0] = 1;

        for (int i = 0; i < n; i++) {
            if (sets[i] == 0) sets[i] = 1;

            queue<int> q;
            q.push(i);

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                int adjSet = sets[node] == 1 ? 2 : 1;
                vector<int> adj = graph[node];
                int adjSize = adj.size();

                for (int j = 0; j < adjSize; j++) {
                    int neighbor = adj[j];

                    if (sets[neighbor] == sets[node]) return false;

                    if (!sets[neighbor]) {
                        sets[neighbor] = adjSet;
                        q.push(neighbor);
                    }
                }
            }
        }

        return true;
    }
};
