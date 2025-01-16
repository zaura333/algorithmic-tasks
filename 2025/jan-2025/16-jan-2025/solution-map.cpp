// 2425. Bitwise XOR of All Pairings
// SOlution with map

#include <utility>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> quantity;
        int n = 0;
        int size1 = nums1.size();
        int size2 = nums2.size();

        if (size2 % 2 == 1) {
            for (int i = 0; i < size1; i++) {
                quantity[nums1[i]] = quantity[nums1[i]] + size2;
            }
        }
        
        if (size1 % 2 == 1) {
            for (int i = 0; i < size2; i++) {
                quantity[nums2[i]] = quantity[nums2[i]] + size1;
            }
        }

        for (pair<int, int> q : quantity) {
            if (q.second % 2 == 1) {
                n = n ^ q.first;
            }
        }

        return n;
    }
};
