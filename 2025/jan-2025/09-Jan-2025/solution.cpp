// 2185. Counting Words With a Given Prefix

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;

        for (int i = 0; i < words.size(); i++) {
            if (words[i].find(pref) == 0) count++;
        }

        return count;
    }
};
