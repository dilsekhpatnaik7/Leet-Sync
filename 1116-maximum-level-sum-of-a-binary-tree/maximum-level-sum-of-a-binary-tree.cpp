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
    int maxLevelSum(TreeNode* root) {
        int level = 1, maximumSum = INT_MIN, ansLevel;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int n = q.size(), currentSum = 0;
            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front(); 
                q.pop();

                currentSum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(currentSum > maximumSum) {
                maximumSum = currentSum;
                ansLevel = level;
            }
            level++;
        }
        return ansLevel;
    }
}; 