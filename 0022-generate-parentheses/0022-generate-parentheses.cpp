class Solution {
public:
    void func(int open,int close,int n,string &s,vector<string> &ans){
        if(close==n&&open==n){
            ans.push_back(s);
            return ;
        }
        if(open<n){
            s.push_back('(');
            func(open+1,close,n,s,ans);
            s.pop_back();
        }
        if(close<open){
            s.push_back(')');
            func(open,close+1,n,s,ans);
            s.pop_back();
        }
        return ;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";
        func(0,0,n,s,ans);
        return ans;
    }
};