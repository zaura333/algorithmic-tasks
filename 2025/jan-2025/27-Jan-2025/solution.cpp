// 1462. Course Schedule IV

#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adjList;

        for (auto edge : prerequisites) {
            adjList[edge[0]].push_back(edge[1]);
        }

        vector<bool> temp(numCourses, false);
        vector<vector<bool>> isPrerequisite(numCourses, temp);

        for (int n = 0; n < numCourses; n++) {
            queue<int> q;
            q.push(n);

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (int adj : adjList[curr]) {
                    if (!isPrerequisite[n][adj]) {
                        isPrerequisite[n][adj] = true;
                        q.push(adj);
                    }
                }
            }
        }
        
        vector<bool> result;

        for (vector<int> query : queries) {
            result.push_back(isPrerequisite[query[0]][query[1]]);
        }

        return result;
    }
};
