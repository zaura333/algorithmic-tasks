// 802. Find Eventual Safe States

#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool isCyclicNode (vector<vector<int>>& graph, int node, vector<bool>& visited, vector<bool>& recStack) {
        if (recStack[node]) return true;
        if (visited[node]) return false;
        
        visited[node] = true;
        recStack[node] = true;

        for (auto& v : graph[node]) {
            if (isCyclicNode(graph, v, visited, recStack)) {
                return true;
            }
        }

        recStack[node] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false);
        vector<bool> recStack(n, false);

        vector<int> safe;

        for (int i = 0; i < n; i++) {
            if (!isCyclicNode(graph, i, visited, recStack))  {
                safe.push_back(i);
            }
        }

        return safe;
    }
};
