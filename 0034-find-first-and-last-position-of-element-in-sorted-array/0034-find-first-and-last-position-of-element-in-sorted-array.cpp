class Solution {
public:
    int first(vector<int> &nums,int target){
        int left = 0;
        int right = nums.size()-1;
        int ans = -1;
        while(left<=right){
            int guess = left + (right-left)/2;
            if(nums[guess]==target){
                ans = guess;
                right = guess-1;
            }
            else if(nums[guess]<target){
                left = guess+1;
            }
            else{
                right = guess-1;
            }
        }
        return ans;
    }
    int last(vector<int> &nums,int target){
        int left = 0;
        int right = nums.size()-1;
        int ans = -1;
        while(left<=right){
            int guess = left + (right-left)/2;
            if(nums[guess]==target){
                ans = guess;
                left = guess+1;
            }
            else if(nums[guess]<target){
                left = guess+1;
            }
            else{
                right = guess-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = first(nums,target);
        int right = last(nums,target);
        return {left,right};
    }
};