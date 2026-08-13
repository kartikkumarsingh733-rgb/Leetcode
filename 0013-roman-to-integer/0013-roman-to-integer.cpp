class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> f = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
        int num = 0;
        int i = s.size()-1;
        while(i>=0){
            char c = s[i];
            int dig = f[c];
            if(i>0&&(c=='V'||c=='X')&&s[i-1]=='I'){
                dig = dig - 1;
                num+=dig;
                i-=2;
            }
            else if(i>0&&(c=='L'||c=='C')&&s[i-1]=='X'){
                dig = dig - 10;
                num+=dig;
                i-=2;
            }
            else if(i>0&&(c=='D'||c=='M')&&s[i-1]=='C'){
                dig = dig - 100;
                num+=dig;
                i-=2;
            }
            else{
                num+=dig;
                i--;
            }

        }

        return num;
    }
};