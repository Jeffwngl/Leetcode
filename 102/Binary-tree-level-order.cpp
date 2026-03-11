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
    void traverseTree(TreeNode* node, int currLevel, vector<vector<int>>& res) {
        if (!node) {
            return;
        }
        else if (res.size() <= currLevel) {
            // cout << res.size() << "\n";
            vector<int>empty;
            res.push_back(empty);
        }

        res[currLevel].push_back(node->val);

        cout << node->val << " " << currLevel << endl;
        
        traverseTree(node->left, currLevel + 1, res); // be careful here, cannot use currLevel++
        traverseTree(node->right, currLevel + 1, res); // int x = 0, int y = x++; -> y = 0, x = 1
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if (root == nullptr) {
            return res;
        }
        // cout << root->val << endl;
        
        traverseTree(root, 0, res);
        return res;
    }
};
