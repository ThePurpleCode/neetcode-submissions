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
    int inorder(TreeNode* root, int& k){ // bst mein inorder traversal lagaya toh sorted values milegi (LNR)
        if(root==NULL || k==0) return -1;

        int l = inorder(root->left, k);// left wala
        if(l!=-1) return l; // agr tereko left mein iterate krte samay hi mil gaya toh l ko hi return kr baki tree traverse krne ki jaroorat nhi

        //jaise hi value pe ho k ko km kr
        k--;
        if(k==0) return root->val; // key cond hai agr and mila yani k==0 hua toh return kr

        int r = inorder(root->right,k);//right pe ja and r return kr taki right mein traverse ho sake
        return r;
    }
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root,k);
    }
};