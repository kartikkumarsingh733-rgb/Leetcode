class Solution {
public:
    bool ispos(vector<int> &nums,int guess,int h){
        int sum = 0;
        for(auto it:nums){
            sum += (it+guess-1)/guess;
            if(sum>h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(),piles.end());
        int res;
        while(left<=right){
            int guess = (left+right)/2;
            if(ispos(piles,guess,h)){
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