// 2467. Most Profitable Path in a Tree

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        graph = buildGraph(edges);
        int n = amount.size();

        visited.assign(n, false);
        findBobPath(bob, 0);


        visited.assign(n, false);
        findAlicePath(0, 0, 0, amount);

        return maxAlice;
    }

    

    private:
    unordered_map<int, vector<int>> graph;
    unordered_map<int, int> bobPath;
    int maxAlice = INT_MIN;
    vector<bool> visited;
    
    unordered_map<int, vector<int>> buildGraph(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;

        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        return graph;
    }

    bool findBobPath(int source, int time) {
        bobPath[source] = time;
        visited[source] = true;

        if (source == 0) {
            return true;
        }

        vector<int> adj = graph[source];

        for (int adjNode : adj) {
            if (!visited[adjNode] && findBobPath(adjNode, time+1)) {
                return true;
            }
        }

        bobPath.erase(source);
        return false;
    }

    void findAlicePath(int source, int time, int income, vector<int>& amount) {
        visited[source] = true;

        if (!bobPath.contains(source) || bobPath[source] > time) {
            income += amount[source];
        } else if (bobPath[source] == time) {
            income += (amount[source] / 2);
        }

        if (graph[source].size() == 1 && source != 0) {
            maxAlice = max(maxAlice, income);
        }

        for (int adjNode : graph[source]) {
            if (!visited[adjNode]) {
                findAlicePath(adjNode, time + 1, income, amount);
            }
        }
    }
};
