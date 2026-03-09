/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    TreeNode* traverseSubtree(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (node == nullptr || node->left == p && node->right == q || 
            node->right == p && node->left == q) {
            return node;
        }

        if ((p->val < node->val && q->val > node->val) || (p->val > node->val && q->val < node->val)) {
            return node;
        }

        if (p->val < node->val && q->val < node->val) {
            return traverseSubtree(node->left, p, q);
        }

        if (p->val > node->val && q->val > node->val) {
            return traverseSubtree(node->right, p, q);
        }

        return node;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return traverseSubtree(root, p, q);
    }
};
