// 916. Word Subsets

class Solution {
public:
    int* getCharsFreq(string& word) {
        auto freqs = new int[26];
        for (char c : word) {
            freqs[c - 'a']++;
        }

        return freqs;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> universal;
        int* maxSubset = new int[26];

        for (int i = 0; i < words2.size(); i++) {
            string word = words2[i];
            int* curr = getCharsFreq(word);

            for (int j = 0; j < 26; j++) {
                maxSubset[j] = max(maxSubset[j], curr[j]);
            }
        }


        for (int i = 0; i < words1.size(); i++) {
            unordered_map<char, int> letters;
            string word = words1[i];
            int* supersetFreq = getCharsFreq(word);

            bool isUniversal = true;

            for (int j = 0; j < 26; j++) {
                if (supersetFreq[j] < maxSubset[j]) {
                    isUniversal = false;
                    break;
                }
            }

            if (isUniversal) universal.push_back(word);
        }

        return universal;
    }
};
