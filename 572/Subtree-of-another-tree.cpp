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
    bool checkSub(TreeNode* originalTree, TreeNode* copyTree) {
        if (originalTree == nullptr && copyTree == nullptr) {return true;}
        if (originalTree == nullptr || copyTree == nullptr) {return false;}
        if (originalTree->val != copyTree->val) {return false;}

        return checkSub(originalTree->left, copyTree->left) && checkSub(originalTree->right, copyTree->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) {return false;}

        if (checkSub(root, subRoot)) {return true;}

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
