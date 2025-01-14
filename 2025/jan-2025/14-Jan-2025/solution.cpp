// 2657. Find the Prefix Common Array of Two Arrays

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int numbers[51] = {0};
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

int main() {
    Solution test;
    vector<int> A = {1, 3, 2, 4};
    vector<int> B = {3, 1, 2, 4};

    cout << "\nTest arrays: ";
    cout << "\nA: ";

    for (int el : A) {
        cout << el << " ";
    }

    cout << "\nB: ";

    for (int el : B) {
        cout << el << " ";
    }

    cout << "\n---\nResult:";
    vector<int> result = test.findThePrefixCommonArray(A, B);
    for (int r : result) {
        cout << " " << r;
    }

    cout << "\nPress any key to exit...";
    cin.get();

    return 0;
}
