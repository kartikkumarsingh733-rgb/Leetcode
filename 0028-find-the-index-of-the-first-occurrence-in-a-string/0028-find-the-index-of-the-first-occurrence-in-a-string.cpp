class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()>haystack.size()) return -1;
        for(int i=0;i<haystack.size()-needle.size()+1;i++){
            string s = haystack.substr(i,needle.size());
            if(s==needle) return i;
        }

        return -1;
    }
};