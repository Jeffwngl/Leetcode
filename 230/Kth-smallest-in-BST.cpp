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
    vector<int>v;
    void inOrder(TreeNode* node, int k) {
        if (!node) {
            return;
        }

        inOrder(node->left, k);

        if (v.size() == k) {
            return;
        }

        v.push_back(node->val);

        inOrder(node->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root) {
            return 0;
        }

        inOrder(root, k);

        // for (auto const& it : v) {
        //     cout << it << endl;
        // }

        return v[v.size() - 1];
    }
};
