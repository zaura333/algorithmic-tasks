// 3042. Count Prefix and Suffix Pairs I

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int matches = 0;
        for (int i = 0; i < words.size() - 1; i++) {
            for (int j = i + 1; j < words.size(); j++) {
                string sufPref = words[i];
                string mainWord = words[j];
                if (i == j) break;

                matches = matches + isPrefixAndSuffix(sufPref, mainWord);
            }
        }

        return matches;
    }

    bool isPrefixAndSuffix(string sufPref, string mainWord) {
        if (sufPref.length() > mainWord.length()) return 0;

        if (sufPref == mainWord) {
            return 1;
        }

        if (mainWord.find(sufPref) == 0) {
            if (0 == mainWord.compare(mainWord.length() - sufPref.length(), sufPref.length(), sufPref)) {
                return 1;
            }
        }

        return 0;
    }
};
