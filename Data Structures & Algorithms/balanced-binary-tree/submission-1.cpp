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
    int depth(TreeNode* root , bool &balanced){
        if(root==NULL) return NULL;

        int l = depth(root->left , balanced);
        int r = depth(root->right , balanced);

        if(abs(l-r)>1) balanced = false;
        return max(l,r) +1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;

        bool balanced = true;
        depth(root,balanced);
        return balanced;
    }
};