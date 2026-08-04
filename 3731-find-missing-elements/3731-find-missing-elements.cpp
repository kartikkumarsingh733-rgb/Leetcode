class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int sizev= nums[n-1]-nums[0]+1;
        vector <int> v(sizev,0);
        int start=nums[0];
        vector <int> ans;
        for(int i=0;i<sizev;i++){
            v[i]=start;
            start++;
        }
        int i=0;
        int j=0;
        while(i<n&&j<sizev){
            if(nums[i]==v[j]){
                i++;
                j++;
            }
            else{
                if(nums[i]>v[j]){
                    ans.push_back(v[j]);
                    j++;
                }
                else{
                    ans.push_back(nums[i]);
                        i++;
                }
            }
        }
    return ans;}
};