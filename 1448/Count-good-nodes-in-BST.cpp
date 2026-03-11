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
    void countNodes(TreeNode* node, int& res, int ancestorMax) {
        if (!node) {
            return;
        }
        int newMax = ancestorMax;
        if (node->val >= ancestorMax) {
            newMax = node->val;
            res++;
        }

        countNodes(node->left, res, newMax);
        countNodes(node->right, res, newMax);
    }
public:
    int goodNodes(TreeNode* root) {
        int res = 0;
        if (!root) {
            return res;
        }
        countNodes(root, res, -99999);
        return res;
    }
};
