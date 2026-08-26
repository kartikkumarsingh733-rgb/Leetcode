class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<string> store;
        int minsize = INT_MAX;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                unordered_map<char,int> f;
                for(int m = i;m<=j;m++){
                    f[s[m]]++;
                    if(f['1']==k){
                        store.push_back(s.substr(i,j-i+1));
                        minsize = min(minsize,j-i+1);
                    } 
                }

            }
        }
        vector<string> temp;
        for(int i=0;i<store.size();i++){
            if(store[i].size()==minsize){
                temp.push_back(store[i]);
            }
        }

        sort(temp.begin(),temp.end());
        if(temp.size()==0) return "";
        return temp[0];
    }
};