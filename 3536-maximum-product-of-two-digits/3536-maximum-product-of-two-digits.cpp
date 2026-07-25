class Solution {
public:
    int maxProduct(int n) {
        int m1 = 0;
        int m2=0;
        int temp1 =n;
        int temp2=n;
        int pos1 = 0;
        while(temp1>0){
            int dig = temp1%10;
            pos1++;
            m1 = max(m1,dig);
            temp1= temp1/10;
        }
        int count=1;
        while(temp2>0){
            int dig = temp2%10;
            if(dig==m1&&count<=1){
                count++;
                dig=0;  
            }
            m2 = max(m2,dig);
            temp2= temp2/10;
        }

        return (long long) m1*m2;
        
    }
    
};