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
    TreeNode* ans=NULL;
    void fun(TreeNode* root,int target){
        if(root==NULL){
            return;
        }
        if(root->val==target){
            ans = root;
            return ;
        }
        else if(root->val>target){
            fun(root->left,target);
        }
        else{
            fun(root->right,target);
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        fun(root,val);
        return ans;
    }
};