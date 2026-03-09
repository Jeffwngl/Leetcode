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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        TreeNode* leftNode = lowestCommonAncestor(root->left, p, q); // returns p, q, null or LCA
        TreeNode* rightNode = lowestCommonAncestor(root->right, p, q);

        if (leftNode && rightNode) { // either p and q have been found in the either the left and right subtrees
            return root;
        }

        return leftNode ? leftNode : rightNode; // if leftNode exists return leftNode else rightNode
    } // it has to have found something, either p/q in left and right or p/q both in left or right
};
