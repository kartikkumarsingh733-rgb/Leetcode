class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> pre(height.size(),0);
        vector<int> post(height.size(),0);

        for(int i=1;i<height.size();i++){
            pre[i] = max(pre[i-1],height[i-1]);
        }
        for(int i=height.size()-2;i>=0;i--){
            post[i] = max(post[i+1],height[i+1]);
        }
        for(int i=0;i<pre.size();i++){
            cout<<pre[i]<<" "<<post[i]<<endl;
        }
        int water=0;
        for(int i=0;i<height.size();i++){ 
            if(min(pre[i],post[i])-height[i]>0){
                water += min(pre[i],post[i])-height[i];
            }
           
        }

        return water;
    }
};