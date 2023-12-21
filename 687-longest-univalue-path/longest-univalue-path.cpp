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
    int dfs(TreeNode* root, int& count) {
        if(!root) return 0;

        int leftPath = dfs(root->left, count);
        int rightPath = dfs(root->right, count);

        int left = 0, right = 0;
        if(root->left && root->val == root->left->val) left = leftPath + 1;
        if(root->right && root->val == root->right->val) right = rightPath + 1;

        count = max(count, left + right);
        return max(left, right);
    }

    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;

        int count = 0;
        dfs(root, count);
        return count;
    }
};