// 2981. Find Longest Special Substring That Occurs Thrice I

class Solution {
public:
    bool checkSpecial(string s) {
        if (s.length() == 0) return false;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != s[0]) {
                return false;
            }
        }
        return true;
    }
    
    int maximumLength(string s) {
        for (int subLength = s.length(); subLength > 0; subLength--) {
            unordered_map<string, int> sMap;

            for (int start = 0; start + subLength <= s.length(); start++) {
                string currS = s.substr(start, subLength);
                if (!checkSpecial(currS)) continue;

                if (sMap.contains(currS)) {
                    sMap[currS] += 1;
                } else {
                    sMap.insert({currS, 1});
                }
            }
            
            for (const auto& [key, value] : sMap) {
                if (value >= 3) return key.length();
            }
        }

        return -1;
    }
};
