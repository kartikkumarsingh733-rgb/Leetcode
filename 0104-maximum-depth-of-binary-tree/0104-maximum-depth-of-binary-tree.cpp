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
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int count=0;
        int res=0;
        while(!q.empty()){
            int lvlsize = q.size();
            while(lvlsize--){
                TreeNode* t = q.front();
                q.pop();
                if(t->left==NULL&&t->right==NULL) res = count+1;
                if(t->left!=NULL) q.push(t->left);
                if(t->right!=NULL) q.push(t->right);

            }
            count++;
        }
        return res;
    }
};