// 2206. Divide Array Into Equal Pairs

#include <vector>
#include <unordered_map>

using std::vector, std::unordered_map;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        for (int& num : nums) {
            freq[num] += 1;
        }

        for (auto& f : freq) {
            if (f.second % 2 != 0) return false;
        }

        return true;
    }
};
