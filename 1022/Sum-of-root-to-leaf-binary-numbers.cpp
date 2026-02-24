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
    int res;
public:
    int getBinary(vector<int>v) {
        int value = 0;
        for (auto it : v) {
            value = (value << 1) | it;
        }
        return value;
    }

    void preOrder(TreeNode* n, vector<int>v) {
        if (n == nullptr) {
            return;
        }
        v.push_back(n->val);
        if (n->left == nullptr && n->right == nullptr) {
            res += getBinary(v);
            return;
        }
        preOrder(n->left, v);
        preOrder(n->right, v);
    }

    int sumRootToLeaf(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
            if (root->val == 1) {
                return 1;
            }
            return 0;
        }

        vector<int>bits;

        preOrder(root, bits);
        return res;
    }
};
