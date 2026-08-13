class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=0;i<s.size();i++){
            unordered_map<char,int> f;
            for(int j=i;j<s.size();j++){
                f[s[j]]++;
                mini = INT_MAX;
                maxi = INT_MIN;
                for(auto it:f){
                mini = min(it.second,mini);
                maxi = max(it.second,maxi);
                }
                sum += maxi - mini;
            }
        }


        return sum ;

    }
};