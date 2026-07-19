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
    void solve(TreeNode* root , int level , vector<int>& view){
        if(root==NULL) return;

        if(view.size()==level) view.push_back(root->val); // hr level pe ek hi hoga na so agr view ki size level ke eq hai toh naye level ka pahela element hai
        // pahela element naye level ka right se dkehna start kr

        solve(root->right,level+1,view);
        solve(root->left,level+1,view); // pahele right then left (modified preorder NRL)

        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        solve(root,0,view);
        return view;
    }
};