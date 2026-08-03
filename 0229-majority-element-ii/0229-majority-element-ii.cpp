class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> f;
        vector<int> res;
        for(auto it:nums){
            f[it]++;
        }
        for(auto it:f){
            if(it.second>nums.size()/3){
                res.push_back(it.first);
            }
        }
        return res;
    }


};