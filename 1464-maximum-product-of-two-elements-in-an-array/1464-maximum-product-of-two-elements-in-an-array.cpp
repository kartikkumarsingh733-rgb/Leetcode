class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first = INT_MIN;
        int freq = 0;
        for(auto it:nums){
            first = max(first,it);
        }
        int sec = INT_MIN;
        for(auto it:nums){
            if(it==first){
                freq++;
                continue;
            }

            sec = max(sec,it);
        }
        if(freq>1) return (long long) (first-1)*(first-1);

        return (long long) (sec-1)*(first-1);
    }
};