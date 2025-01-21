// 2017. Grid Game

#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        vector<int> top = grid[0];
        vector<int> bottom = grid[1];

        long long topSum = accumulate(top.begin() + 1, top.end(), 0LL);
        long long bottomSum = bottom[0];

        long long redDropI = 0LL;

        while (topSum > bottomSum && redDropI < top.size() - 1) {
            redDropI++;
            topSum -= top[redDropI];
            bottomSum += bottom[redDropI];
        }

        bottomSum -= bottom[redDropI];

        return max(topSum, bottomSum);
    }
};
