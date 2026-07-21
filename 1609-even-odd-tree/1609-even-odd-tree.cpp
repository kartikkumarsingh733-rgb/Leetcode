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
    bool isEvenOddTree(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);
        int i=0;
        while(!q.empty()){
            int lvlsize = q.size();
            int prev = (i % 2 == 0) ? INT_MIN : INT_MAX;
            while(lvlsize--){
                TreeNode* t = q.front();
                q.pop();
                if(i%2==0){
                    if(t->val%2==0) return false;
                    if(t->val<=prev) return false;
                }
                else{
                    if(t->val%2!=0) return false;
                    if(t->val>=prev) return false;

                }
                prev = t->val;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            i++;
        }

        return true;
    }
};