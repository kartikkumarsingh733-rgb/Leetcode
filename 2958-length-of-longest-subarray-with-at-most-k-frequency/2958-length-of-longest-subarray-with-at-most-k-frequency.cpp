class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int low = 0;
        int high = 0;
        unordered_map<int,int> f;
        int res = INT_MIN;
        for(high=0;high<nums.size();high++){
            f[nums[high]]++;
            
            while(f[nums[high]]>k){
                f[nums[low]]--;
                if(f[nums[low]]==0){
                    f.erase(nums[low]);
                }
                low++;
            }
            int len = high-low+1;
            res = max(res,len);
            
            
        }

        return res;
    }
};