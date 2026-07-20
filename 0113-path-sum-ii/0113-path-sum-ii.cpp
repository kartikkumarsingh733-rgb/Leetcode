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
    bool once = false;
    void func(TreeNode* root,int sum,int target,vector<vector<int>>&ans,vector<int> &diary){
        if(root==NULL) return;
        sum+=root->val;
        diary.push_back(root->val);
        if(root->left==NULL&&root->right==NULL){
            if(sum==target){
                ans.push_back(diary);
            }
        }
        else{
            func(root->left,sum,target,ans,diary);
            func(root->right,sum,target,ans,diary);
        }
        diary.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> diary;
        int sum=0;
        func(root,sum,targetSum,ans,diary);
        return ans;
    }
};