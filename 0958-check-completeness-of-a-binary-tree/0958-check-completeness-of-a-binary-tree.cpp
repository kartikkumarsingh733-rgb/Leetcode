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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while(!q.empty()){
            int lvlsize=q.size();
            while(lvlsize--){
                TreeNode* t = q.front();
                q.pop();
                if(t==NULL) flag=true;
                else{
                    if(flag) return false;
                    q.push(t->left);
                    q.push(t->right);
                }
             }
        }

        return true;
    }
};