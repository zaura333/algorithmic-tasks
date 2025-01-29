// 684. Redundant Connection
// Union find

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int find(int node, int* parent) {
        if (parent[node] == node) {
            return node;
        }

        return find(parent[node], parent);
    }

    void reroot(int node, int newParent, int* parent) {
        if (parent[node] != node) {
            reroot(parent[node], node, parent);
        }

        parent[node] = newParent;
        return;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        int* parent = new int[n + 1];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        vector<int> toDelete = {-1, -1};

        for (vector<int> edge : edges) {
            int first = edge[0] - 1;
            int second = edge[1] - 1;
            int parentFirst = find(first, parent);
            int parentSecond = find(second, parent);

            if (parentFirst == parentSecond) {
                toDelete = edge;
            } else if (parentSecond != second && parentFirst == first) {
                parent[first] = second;
            } else if (parentSecond != second && parentFirst != first) {
                reroot(second, first, parent);
            } else {
                parent[second] = first;
            }
        }

        delete[] parent;
        return toDelete;
    }
};
