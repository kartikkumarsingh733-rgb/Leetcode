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
    struct obj{
        TreeNode* node;
        int col;
        int row;
    };
    struct cmp{
        bool operator()(const obj &a,const obj &b){
            if (a.col != b.col) return a.col > b.col;   // smaller col first
            if (a.row != b.row) return a.row > b.row;   // smaller row first
            return a.node->val > b.node->val; 
        }
    };
    void func(TreeNode* root,priority_queue<obj,vector<obj>,cmp>&pq,int i,int j){
        if(root==NULL) return ;

        struct obj object;
        object.node = root;
        object.row = i;
        object.col = j;
        pq.push(object);

        func(root->left,pq,i+1,j-1);
        func(root->right,pq,i+1,j+1);

        return ;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        priority_queue<obj,vector<obj>,cmp> pq;
        func(root,pq,0,0);
        vector<vector<int>> ans;
        vector<int> temp;
        int prev = INT_MIN;
        while(!pq.empty()){
            auto object = pq.top();
            pq.pop();
            int curr = object.col;
            if(prev==INT_MIN||prev==curr){
                temp.push_back(object.node->val);
            }
            else{
                ans.push_back(temp);
                temp.clear();
                temp.push_back(object.node->val);
            }
            prev = curr;
        }
        if(!temp.empty()) ans.push_back(temp);

        return ans;
    }
};