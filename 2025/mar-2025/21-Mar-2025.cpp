// 2115. Find All Possible Recipes from Given Supplies

#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using std::vector, std::string, std::unordered_set, std::unordered_map, std::queue;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> availableSupplies;
        unordered_map<string, int> recipeToIndex;
        unordered_map<string, vector<string>> dependencyGraph;

        for (string& supply : supplies) {
            availableSupplies.insert(supply);
        }

        for (int i = 0; i < recipes.size(); i++) {
            recipeToIndex[recipes[i]] = i;
        }

        vector<int> inDegree(recipes.size(), 0);

        for (int j = 0; j < recipes.size(); j++) {
            for (string& ingredient : ingredients[j]) {
                if (!availableSupplies.count(ingredient)) {
                    dependencyGraph[ingredient].push_back(recipes[j]);
                    inDegree[j]++;
                }
                
            }
        }

        queue<string> recipesQ;

        for (int k = 0; k < recipes.size(); k++) {
            if (inDegree[k] == 0) recipesQ.push(recipes[k]);
        }

        vector<string> createdRecipes;

        while (!recipesQ.empty()) {
            string currRecipe = recipesQ.front();
            recipesQ.pop();
            createdRecipes.push_back(currRecipe);

            if (!dependencyGraph.count(currRecipe)) continue;

            for (string& dependent : dependencyGraph[currRecipe]) {
                if (--inDegree[recipeToIndex[dependent]] == 0) {
                    recipesQ.push(dependent);
                } 
            }
        }

        return createdRecipes;
    }
};
