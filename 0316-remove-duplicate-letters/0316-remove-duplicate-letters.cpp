class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool> used(26,false);
        unordered_map<char,int> freq;
        for(char it : s) freq[it]++;

        string ans="";
        for(int i=0;i<s.size();i++){
            char c = s[i];
            freq[c]--;  // decrement count for current char

            if(used[c-'a']) continue;

            // shrink while last char is bigger and still available later
            while(!ans.empty() && c < ans.back() && freq[ans.back()] > 0){
                used[ans.back()-'a'] = false;
                ans.pop_back();
            }

            ans.push_back(c);
            used[c-'a'] = true;
        }
        return ans;
    }
};

