// 3108. Minimum Cost Walk in Weighted Graph

#include <vector>

using std::vector;

class Solution {
public:
    vector<int> parent;
    vector<int> depth;
    
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n, -1);
        depth.resize(n, 0);

        vector<unsigned int> weights(n, -1);

        for (auto& edge : edges) {
            unite(edge[0], edge[1], edge[2], weights);
        }

        for (auto& edge : edges) {
            int root = findRoot(edge[0]);
            weights[root] &= edge[2];
        }

        vector<int> result;

        for (auto& q : query) {
            int root1 = findRoot(q[0]);
            int root2 = findRoot(q[1]);

            if (root1 != root2) {
                result.push_back(-1);
                continue;
            }

            result.push_back(weights[root1]);
        }

        return result;
    }

    private:
    int findRoot(int i) {
        if (parent[i] == -1) {
            return i;
        }

        return parent[i] = findRoot(parent[i]);
    }

    void unite(int node1, int node2, int weight, vector<unsigned int>& weights) {
        int rep1 = findRoot(node1);
        int rep2 = findRoot(node2);

        if (rep1 == rep2) return;

        if (depth[rep1] < depth[rep2]) std::swap(rep1, rep2);

        parent[rep2] = rep1;

        if (depth[rep1] == depth[rep2]) depth[rep1]++;
    }
};
