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
    bool allowedval(TreeNode* root , long long int low , long long high){ // check allowed values for each node 
        if(root==NULL) return true;

        if(root->val >=high || root->val<=low) return false;

        bool lft = allowedval(root->left,low,root->val);
        bool right = allowedval(root->right,root->val,high);

        if(lft && right) return true;
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return allowedval(root,LLONG_MIN , LLONG_MAX);
    }
};