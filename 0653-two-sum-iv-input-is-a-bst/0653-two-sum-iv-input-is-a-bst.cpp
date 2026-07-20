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
    stack<TreeNode*> asc;
    stack<TreeNode*> desc;
    TreeNode* getbig(){
        if(desc.empty()) return NULL;
        TreeNode* big = desc.top();
        desc.pop();
        TreeNode* temp = big->left;
        while(temp){
            desc.push(temp);
            temp = temp->right;
        }
        return big;
    }
    TreeNode* getsmall(){
        if(asc.empty()) return NULL;
        TreeNode* small = asc.top();
        asc.pop();
        TreeNode* temp = small->right;
        while(temp){
            asc.push(temp);
            temp = temp->left;
        }
        return small;
    }
    bool findTarget(TreeNode* root, int k) {
        TreeNode* t= root;
        while(t){
            asc.push(t);
            t = t->left;
        }
        t=root;
        while(t){
            desc.push(t);
            t = t->right;
        }
        TreeNode* i = getsmall();
        TreeNode* j = getbig();
        while(i&&j&&i!=j&&i->val<j->val){
            int sum = i->val+j->val;
            if(sum==k) return true;
            else if(sum<k){
                i = getsmall();
            }
            else{
                j = getbig();
            }
        }
        return false;
    }
};