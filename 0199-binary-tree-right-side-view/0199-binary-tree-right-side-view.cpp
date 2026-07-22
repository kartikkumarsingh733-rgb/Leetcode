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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        while(!q.empty()){
            int lvlsize = q.size();
            int flag = true;
            while(lvlsize--){
                TreeNode* t = q.front();
                q.pop();
                if(flag){
                    ans.push_back(t->val);
                    flag = false;
                }

                if(t->right) q.push(t->right);
                if(t->left) q.push(t->left);;
            }
        }

        return ans;
    }
};