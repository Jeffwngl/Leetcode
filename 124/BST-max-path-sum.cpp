/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int res = -1001;
    int dfs(TreeNode* node) {
        if (!node) {
            return 0;
        }

        int l = std::max(0, dfs(node->left)); // -2
        int r = std::max(0, dfs(node->right)); // 3

        res = std::max(res, l + r + node->val); // 3

        return node->val + std::max(l, r);
    }

public:
    int maxPathSum(TreeNode* root) {
        if (!root->left && !root->right) {
            return root->val;
        }
        dfs(root);
        return res;
    }
};
