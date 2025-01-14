// 2657. Find the Prefix Common Array of Two Arrays

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        const int n = A.size();
        int numbers[51];
        vector<int> common;
        int commonCount = 0;

        for (int i = 0; i < A.size(); i++) {
            int currA = A[i];
            int currB = B[i];
            numbers[currA]++;

            if (numbers[currA] == 2) {
                commonCount++;
            }

            numbers[currB]++;

            if (numbers[currB] == 2) {
                commonCount++;
            }

            common.push_back(commonCount);
        }

        return common;
    }
};
