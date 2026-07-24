/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans = NULL;   

    int func(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return 0;   

        int left = func(root->left, p, q);
        int right = func(root->right, p, q);

        int self = (root == p || root == q) ? 1 : 0;
        int total = left + right + self;

        if (!ans && total == 2) {
            ans = root;
        }

        return total;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        func(root, p, q);
        return ans;
    }
};
