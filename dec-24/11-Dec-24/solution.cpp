// 2779. Maximum Beauty of an Array After Applying Operation
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int start = 0;
        int end = 1;
        
        int minStart = sorted[start] - k;
        int maxStart = sorted[start] + k;

        while (end != sorted.size()) {
            int minEnd = sorted[end] - k;
            int maxEnd = sorted[end] + k;

            if ((minEnd < minStart && maxEnd < minStart)
                || (minEnd > maxStart && maxEnd > maxStart)) {
                start++;
                minStart = sorted[start] - k;
                maxStart = sorted[start] + k;
            }

            end++;
        }

        return end - start;
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = vector<int>({ 1,2,4 });
    int result = sol.maximumBeauty(v1, 2);
    cout << result;
}

