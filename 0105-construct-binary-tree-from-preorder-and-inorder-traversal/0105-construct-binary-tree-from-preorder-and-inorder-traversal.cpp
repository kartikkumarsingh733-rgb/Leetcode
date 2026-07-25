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
    unordered_map<int,int> index;
    int idx = 0;

    TreeNode* build(vector<int> &inorder,vector<int> &preorder,int low,int high){
        if(low>high) return NULL;

        TreeNode* node = new TreeNode(preorder[idx]);
        idx++;
        int id = index[node->val];
        node->left =build(inorder,preorder,low,id-1);
        node->right =build(inorder,preorder,id+1,high);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            index[inorder[i]]=i;
        }
        return build(inorder,preorder,0,inorder.size()-1);

    }
};