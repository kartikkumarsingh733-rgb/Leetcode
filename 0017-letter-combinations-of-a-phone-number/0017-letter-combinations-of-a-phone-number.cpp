class Solution {
public:
    void func(string &s,int n,int idx,string &diary,vector<string> &ans,unordered_map<char,string> &f){
        if(idx==n){
            ans.push_back(diary);
            return ;
        }
        string choices = f[s[idx]];
        for(int j=0;j<choices.size();j++){
            diary.push_back(choices[j]);
            func(s,n,idx+1,diary,ans,f);
            diary.pop_back();
        }
        return ;
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> f;
        f['2']="abc";
        f['3']="def";
        f['4']="ghi";
        f['5']="jkl";
        f['6']="mno";
        f['7']="pqrs";
        f['8']="tuv";
        f['9']="wxyz";
        vector<string> ans;
        string diary="";
        int idx=0;
        int n = digits.size();
        func(digits,n,idx,diary,ans,f);

        return ans;
    }
};