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
    TreeNode* build(vector<int>& inorder,vector<int>& postorder,int low,int high,int &idx){
        if(low>high||idx<0) return NULL;
        TreeNode* node = new TreeNode(postorder[idx]);
        idx--;
        int id = index[node->val];
        node->right = build(inorder,postorder,id+1,high,idx);
        node->left = build(inorder,postorder,low,id-1,idx);

        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            index[inorder[i]]=i;
        }
        int i = inorder.size()-1;
        return build(inorder,postorder,0,inorder.size()-1,i);
    }
};