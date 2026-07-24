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
    int dfs(TreeNode* root , int mx){
        if(root==NULL) return 0;

        int ct=0;
        if(root->val>=mx){
            ct++;
            mx = root->val;
        }

        int lft = dfs(root->left,mx);
        int right = dfs(root->right,mx);

        return lft + right +ct;
    }
    int goodNodes(TreeNode* root) {
        int mx=root->val;
        return dfs(root,mx);
    }
};