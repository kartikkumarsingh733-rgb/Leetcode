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
    bool same(TreeNode* p,TreeNode* q){
        if(p==NULL&&q==NULL) return true;

        if(p!=NULL&&q==NULL||p==NULL&&q!=NULL) return false;
        if(p->val!=q->val) return false;

        if(same(p->left,q->left)&&same(p->right,q->right)) return true;

        return false;
    }
    void func(TreeNode* root,TreeNode* subtree,bool &ans){
        if(root==NULL) return;

        func(root->left,subtree,ans);
        if(same(root,subtree)){
            ans=true;
            return ;
        }
        func(root->right,subtree,ans);

        return  ;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ans = false;
        func(root,subRoot,ans);

        return ans;
    }
};