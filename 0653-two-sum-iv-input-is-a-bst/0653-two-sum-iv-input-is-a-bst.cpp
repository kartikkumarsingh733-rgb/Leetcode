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
    void func(TreeNode* root,vector<int> &arr){
        if(root==NULL){
            return ;
        }
        func(root->left,arr);
        arr.push_back(root->val);
        func(root->right,arr);

        return;
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        func(root,arr);
        for(auto it:arr){
            cout<<it<<" ";
        }
        int i=0;
        int j=arr.size()-1;
        while(i<j){
            int sum = arr[i]+arr[j];
            if(sum==k) return true;
            else if(sum<k) i++;
            else j--;
        }

        return false;
    }
};