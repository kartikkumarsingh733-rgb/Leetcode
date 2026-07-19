class Solution {
public:
    struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            // Combine hashes (a common technique)
            seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
        }
    };
    void func(vector<int> &nums,int idx,vector<int> &diary,unordered_set<vector<int>, VectorHash> &s){
        if(idx==nums.size()){
                s.insert(diary);
                return;
            }
            if(idx>=nums.size()) return ;

            diary.push_back(nums[idx]);
            func(nums,idx+1,diary,s);
            diary.pop_back();

            func(nums,idx+1,diary,s);

            return ;
        }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_set<vector<int>, VectorHash> s;
        vector<vector<int>> ans;
        vector<int> diary;
        int idx=0;
        func(nums,idx,diary,s);
        for(auto it:s){
            ans.push_back(it);
        }
        return ans;
    }

};