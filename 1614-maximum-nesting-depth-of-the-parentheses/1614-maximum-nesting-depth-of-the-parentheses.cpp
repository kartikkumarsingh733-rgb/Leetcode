class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int res = 0;
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(c=='(') depth++;
            if(c==')'){
                res = max(res,depth);
                depth--;
            }
        }
        return res;
    }
};