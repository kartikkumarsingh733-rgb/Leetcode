class Solution {
public:
    bool ans = true;
    long long prev = LLONG_MIN; 

    void func(TreeNode* root) {
        if (!root || !ans) return;

        func(root->left);

        if (root->val <= prev) {
            ans = false;
            return;
        }
        prev = root->val;

        func(root->right);
    }

    bool isValidBST(TreeNode* root) {
        func(root);
        return ans;
    }
};
