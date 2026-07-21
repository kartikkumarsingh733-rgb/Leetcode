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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        while(!q.empty()){
            int lvlsize = q.size();
            int maxi = INT_MIN;
            while(lvlsize--){
                TreeNode* t = q.front();
                q.pop();
                maxi = max(maxi,t->val);

                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            ans.push_back(maxi);
        }

        return ans;
    }
};