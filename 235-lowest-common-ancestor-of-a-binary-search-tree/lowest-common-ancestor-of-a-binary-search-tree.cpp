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
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;

        int value = root->val;
        if(p->val < value && q->val < value) return solve(root->left, p, q);
        else if(p->val > value && q->val > value) return solve(root->right, p, q);
        else return root;
    } 

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};