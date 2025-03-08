// 2379. Minimum Recolors to Get K Consecutive Black Blocks

#include <vector>
#include <string>

using std::vector, std:: string, std::max;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i = 0;
        int j = 0;
        int maxB = 0;
        int currB = blocks[0] == 'B' ? 1 : 0;

        while (j < blocks.size()) {
            while (j != i + k - 1) {
                j++;
                if (j == blocks.size()) break;
                if (blocks[j] == 'B') {
                    currB++;
                }
            }

            maxB = max(maxB, currB);

            if (blocks[i] == 'B') currB--;
            i++;
        }

        return k - maxB;
    }
};
