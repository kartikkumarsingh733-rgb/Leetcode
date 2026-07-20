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
    TreeNode* func(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root->val==p->val||root->val==q->val){
            return root;
        }
        if(p->val<root->val&&root->val<q->val){
            return root;
        }
        if(root->val<p->val){
            return(func(root->right,p,q));   
        }
        if(root->val>q->val){
            return(func(root->left,p,q));
        }
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* mini=NULL;
        TreeNode* maxi=NULL;
        if(p->val<q->val){
            mini = p;
            maxi=q;
        }
        else{
            mini=q;
            maxi=p;
        }

        TreeNode* ans = func(root,mini,maxi);
        return ans;
    }
};