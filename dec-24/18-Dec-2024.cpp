// 1475. Final Prices With a Special Discount in a Shop
// Monothonic stack

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> indicesStack;
        vector<int> discounted = prices;

        for (int i = 0; i < prices.size(); i++) {
            while (!indicesStack.empty() && prices[indicesStack.top()] >= prices[i]) {
                discounted[indicesStack.top()] = prices[indicesStack.top()] - prices[i];
                indicesStack.pop();
            }
            indicesStack.push(i);
        }

        return discounted;
    }
};

int main()
{
    Solution sol;
    vector<int> v1 = vector<int>({ 10,1,1,6 });
    vector<int> result = sol.finalPrices(v1);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
    }
    
}
