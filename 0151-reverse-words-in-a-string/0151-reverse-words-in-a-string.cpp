class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int i = 0;
        while(i < s.size()){
            // skip spaces
            while(i < s.size() && s[i] == ' ') i++;

            if(i >= s.size()) break;

            int j = i;
            while(i < s.size() && s[i] != ' ') i++;

            words.push_back(s.substr(j, i - j));
        }

        reverse(words.begin(), words.end());

        string res;
        int n = words.size();
        for(int k = 0; k < n; k++){
            if(k > 0) res += " ";
            res += words[k];
        }
        return res;
    }
};
