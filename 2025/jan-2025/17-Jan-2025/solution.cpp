// 2683. Neighboring Bitwise XOR

#include <vector>
using namespace std;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int result = 0;

        for (int i = 0; i < n; i++) {
            result ^= derived[i];
        }

        return result == 0 ? true : false;
    }
};
