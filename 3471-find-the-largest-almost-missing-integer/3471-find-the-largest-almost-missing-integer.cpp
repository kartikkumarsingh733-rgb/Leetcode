class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        if (k == n) {
            int max_val = INT_MIN;
            for (int num : nums) {
                max_val = max(max_val, num);
            }
            return max_val;
        }

        if (k == 1) {
            int ans = -1;
            for (auto& [num, freq] : count) {
                if (freq == 1) {
                    ans = max(ans, num);
                }
            }
            return ans;
        }

        
        int ans = -1;
        if (count[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }
        if (count[nums[n-1]] == 1) {
            ans = max(ans, nums[n-1]);
        }

        return ans;
    }
};