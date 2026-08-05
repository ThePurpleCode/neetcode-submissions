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
public: // dp lagega jo hr node pe 2 options honge ya toh pick kr ya toh nhi..(agar pick kia toh next nhi pick kr sakte yani children) // dp
    pair<int,int> dfs(TreeNode* root){ // pair mein {mx if robbed , mx if not robbed}
        if(root==NULL) return {0,0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        //case 1 rob this node .. cannot rob its children
        int rob_node = root->val + left.second + right.second; // root->val -- rob kr , left(root->left child) ka second mane not robbing that same with right;

        // case 2 root ko rob nhi krna toh right and left ko rob kr sakte(kr sakte does not mean karna hi hai check mx)
        int no_rob = max(left.first,left.second) + max(right.first , right.second);

        return {rob_node,no_rob};

    }
    int rob(TreeNode* root) {
        auto ans = dfs(root);
        return max(ans.first,ans.second);
    }
};