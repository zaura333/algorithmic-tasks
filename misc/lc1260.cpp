// 1261. Find Elements in a Contaminated Binary Tree

#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FindElements {
public:
    unordered_set<int> values;
    FindElements(TreeNode* root) {
        if (root->val == -1) root->val = 0;

        populateTree(root);
    }

    void populateTree(TreeNode* root) {
        if (root == nullptr) return;
        values.insert(root->val);
        if (root->left != nullptr && root->left->val == -1) {
            root->left->val = 2 * root->val + 1;
            populateTree(root->left);
        }

        if (root->right != nullptr && root->right->val == -1) {
            root->right->val = 2 * root->val + 2;
            populateTree(root->right);
        }
    }
    
    bool find(int target) {
        return values.contains(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
