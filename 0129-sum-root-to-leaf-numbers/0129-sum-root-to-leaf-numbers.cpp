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
    void func(TreeNode* root,int &num,int &sum){
        if(root==NULL) return;
        int dig = root->val%10;
        num = num*10+dig;
        if(root->left==NULL&&root->right==NULL){
            sum+=num;
        }
        else{
            func(root->left,num,sum);
            func(root->right,num,sum);
        }
        num = num/10;
        return;
    }
    int sumNumbers(TreeNode* root) {
        int num =0;
        int sum=0;
        func(root,num,sum);
        return sum;
    }
};