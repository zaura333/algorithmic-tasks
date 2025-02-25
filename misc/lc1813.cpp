// 1813. Sentence Similarity III

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using std::string, std::vector, std::stringstream, std::min;

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> arr1 = splitString(sentence1, ' ');
        vector<string> arr2 = splitString(sentence2, ' ');

        int n1 = arr1.size();
        int n2 = arr2.size();
        int n = min(n1, n2);

        int longestCommon = 0;

        for (int i = 0; i < n; i++) {
            if (arr1[i] != arr2[i]) {
                break;
            }

            longestCommon++;
        }

        if (longestCommon == n) return true;

        for (int j = 1; j <= n && longestCommon != n; j++) {
            if (arr1[n1 - j] != arr2[n2 - j]) {
                break;
            }

            longestCommon++;
        }

        return longestCommon == n;
    }

private:
    vector<string> splitString(string str, char del) {
        stringstream ss(str);
        vector<string> splitted;
        string t;

        while (getline(ss, t, del)) {
            splitted.push_back(t);
        }

        return splitted;
    }
};
