// 1408. String Matching in an Array

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        string joined = words[0];
        vector<string> substrings;

        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if (i == j) continue;

                if (words[j].find(words[i]) != string::npos) {
                    substrings.push_back(words[i]);
                    break;
                }
            }
        }

        string n = "leetcode";
        string m = "code";

        cout << (n.find(m) != string::npos);

        return substrings;
    }
};
