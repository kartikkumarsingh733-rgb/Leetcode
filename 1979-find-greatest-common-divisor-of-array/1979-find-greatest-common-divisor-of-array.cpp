class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini=1001;
        int maxi=0;
        for(auto it:nums){
            mini = min(mini,it);
        }
        for(auto it:nums){
            maxi = max(maxi,it);
        }

        return gcd(mini,maxi);
    }
};