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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> level;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        if(root==NULL) return ans;

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp==NULL){//level change ho gaya hai ans mein level dal
                ans.push_back(level);
                level.clear();
                if(!q.empty()) q.push(NULL); // agr queue empty hai toh cusion ke liye NULL daal de taki q empty hoke exit na ho
            }
            else{
                level.push_back(temp->val); // level mein val daal 
                if(temp->left) q.push(temp->left); // is temp ke left right check kr agar hai toh daal de
                if(temp->right) q.push(temp->right);
            }
        }
        return ans;

    }
};