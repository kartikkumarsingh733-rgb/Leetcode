class Solution {
public:
    // Function to compute max depth of a subtree
    int maxl(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + max(maxl(root->left), maxl(root->right));
    }

    // Function to compute diameter
    void func(TreeNode* root, int &res) {
        if (root == NULL) return;

        int leftDepth = maxl(root->left);
        int rightDepth = maxl(root->right);

        // Update diameter
        res = max(res, leftDepth + rightDepth);

        // Recurse on children
        func(root->left, res);
        func(root->right, res);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        func(root, res);
        return res;
    }
};
