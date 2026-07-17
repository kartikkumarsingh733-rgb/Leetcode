class Solution {
public:
    void func(vector<int> &nums,int idx,vector<int> &diary,vector<vector<int>> &ans,vector<bool> &used){
        if(diary.size()==nums.size()){
            ans.push_back(diary);
            return;
        }
        if(diary.size()>nums.size()) return;
        for(int i=0;i<nums.size();i++){
            if(used[i]) continue;

            used[i]=true;
            diary.push_back(nums[i]);
            func(nums,i+1,diary,ans,used);
            diary.pop_back();
            used[i]=false;
        }

        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> diary;
        int idx=0;
        vector<bool> used(nums.size(),false);
        func(nums,idx,diary,ans,used);

        return ans;
    }
};