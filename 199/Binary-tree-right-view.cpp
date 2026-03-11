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
    void levelTraverse(vector<int>& res, vector<TreeNode*> currLevel) {
        while (currLevel.size() > 0) {
            vector<TreeNode*>nextLevel;
            res.push_back(currLevel[currLevel.size() - 1]->val);
            for (auto const& n : currLevel) {
                if (n->left) {
                    nextLevel.push_back(n->left);
                }
                if (n->right) {
                    nextLevel.push_back(n->right);
                }
            }
            currLevel = nextLevel;
        }
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        vector<TreeNode*>curr;
        if (!root) {
            return res;
        }
        curr.push_back(root);
        levelTraverse(res, curr);
        return res;
    }
};
