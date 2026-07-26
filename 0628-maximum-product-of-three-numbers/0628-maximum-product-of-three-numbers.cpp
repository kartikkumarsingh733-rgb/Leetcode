class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size()==3){
            int prod = 1;
            for(auto it:nums){
                prod*=it;
            }
            return prod;
        }
        sort(nums.begin(),nums.end());
        int ans1 = nums[0]*nums[1]*nums[nums.size()-1];
        int ans2 = nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3];

        return max(ans1,ans2);
    }
};