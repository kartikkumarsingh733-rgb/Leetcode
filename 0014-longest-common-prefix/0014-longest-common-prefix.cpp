class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(int i=1;i<strs.size();i++){
            string temp = "";
            for(int j=0;j<strs[i].size();j++){
                if(j<ans.size()&&ans[j]==strs[i][j]){
                    temp.push_back(strs[i][j]);
                }
                if(j<ans.size()&&ans[j]!=strs[i][j]) break;
                if(j>=ans.size()) break;
            }
            ans = temp;
        }

        return ans;
    }
};