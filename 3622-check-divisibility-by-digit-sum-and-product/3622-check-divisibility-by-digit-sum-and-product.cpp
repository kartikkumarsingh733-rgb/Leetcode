class Solution {
public:
    bool checkDivisibility(int n) {
        int sum  = 0;
        int prod = 1;
        int copy = n;
        while(copy>0){
            int dig = copy%10;
            copy = copy/10;
            sum+=dig;
            prod*=dig;
        }
        int total = sum + prod;

        return(n%total==0);
    }
};