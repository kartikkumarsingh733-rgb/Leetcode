class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int open = 0;
        int close = 0;
        stack<char> stk;
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(c=='(') open++;
            if(c==')') close++;
            if(!stk.empty()&&close==open){
                int len = stk.size();
                string temp = "";
                while((len--)>1){
                    temp.push_back(stk.top());
                    stk.pop();
                }
                if(stk.size()!=0)stk.pop();
                reverse(temp.begin(),temp.end());
                ans+=temp;
                open = 0;
                close = 0;
                continue;
            }
            stk.push(c);
        }
        return ans;
    }
};