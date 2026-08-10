class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int open = 0;
        int close =0;
        int bidx = 0;
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(c=='(') open++;
            if(c==')') close++;
            if(close==open){
                ans+= s.substr(bidx+1,i-bidx-1);
                bidx = i+1;
            }
        }

        return ans;
    }
};