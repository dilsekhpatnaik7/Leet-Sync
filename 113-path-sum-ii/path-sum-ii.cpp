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
public:
    void dfs(TreeNode* root, int targetSum, vector<int> t, vector<vector<int>>& ans) {
        if(!root) return;
        if(!root->right && !root->left) {
            if(root->val == targetSum) {
                t.push_back(root->val);
                ans.push_back(t);
            }
            return;
        }

        t.push_back(root->val);
        dfs(root->left, targetSum - root->val, t, ans);
        dfs(root->right, targetSum - root->val, t, ans);
        t.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};

        vector<int> t;
        vector<vector<int>> ans;
        dfs(root, targetSum, t, ans);

        return ans;
    }
};