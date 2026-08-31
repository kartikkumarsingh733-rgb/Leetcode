class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n-1;
        int water = 0;
        int maxarea = INT_MIN;
        while(left<right){
            int len = right-left;
            int h = min(height[left],height[right]);
            water = (long long)len*h;
            maxarea = max(maxarea,water);
            if(height[left]==h){
                while(left<right&&height[left]<=h){
                    left++;
                }
            }
            else{
                while(left<right&&height[right]<=h){
                    right--;
                }
            }
        }
        return maxarea;
    }
};