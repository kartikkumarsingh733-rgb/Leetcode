class Solution {
public:
    bool ispos(vector<int> &nums,int tresh,int guess){
        int sum = 0;
        for(auto it:nums){
            if(it==guess){
                sum+=it/guess;
            }
            else if(it<guess){
                sum+=1;
            }
            else{
                if(it%guess==0){
                    sum+= it/guess;
                }
                else{
                    sum+= it/guess +1;
                }
            }
        }

        return sum<=tresh;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = *max_element(nums.begin(),nums.end());
        int res = INT_MIN;
        while(left<=right){
            int guess = (left+right)/2;

            if(ispos(nums,threshold,guess)){
                res = guess;
                right = guess-1;
            }
            else{
                left = guess+1;
            }
        }

        return res;
    }
};