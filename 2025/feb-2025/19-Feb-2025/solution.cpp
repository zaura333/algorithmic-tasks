// 1415. The k-th Lexicographical String of All Happy Strings of Length n

#include <string>
#include <set>

using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {
        set<string> happyStrings;
        constructHappyString(n, "", happyStrings);
        // cout << happyStrings.size() << "\n";

        int i = 0;
        for (const auto& str : happyStrings) {
            i++;
            if (i == k) return str;
            // std::cout << str << "\n";
        }

        return "";
    }

    void constructHappyString(int n, string base, set<string>& happyStrings) {
        // std::cout << base << "\n";
        int currLength = base.length();
        if (currLength == n) {
            // cout << "here\n";
            happyStrings.insert(base);
            // cout << happyStrings.size() << "\n";
            return;
        }

        for (int i = 0; i < 3; i++) {
            char currChar = static_cast<char>(97 + i);

            if (currLength > 0 && base[currLength - 1] == currChar) {
                continue;
            }
            string newBase = base + currChar;

            constructHappyString(n, newBase, happyStrings);
        }
    }
};
