class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> f;
        for(int i=0; i<nums.size(); i++){
            int complement = target - nums[i];
            if(f.find(complement) != f.end()){
                return {f[complement], i};
            }
            f[nums[i]] = i;
        }
        return {-1,-1};
    }
};
