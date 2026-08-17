class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()==1) return heights[0];

        vector<int> next(heights.size(),heights.size());
        vector<int> prev(heights.size(),-1);

        stack<int> stk;

        for(int i=heights.size()-1;i>=0;i--){
            while(!stk.empty()&&heights[stk.top()]>=heights[i]){
                stk.pop();
            }
            
            if(!stk.empty()) next[i] = stk.top();
            stk.push(i);
        }
        while(!stk.empty()) stk.pop();
        for(int i=0;i<heights.size();i++){
            while(!stk.empty()&&heights[stk.top()]>=heights[i]){
                stk.pop();
            }
            
            if(!stk.empty()) prev[i] = stk.top();
            stk.push(i);
        }
        int maxarea = -1;
        for(int i=0;i<heights.size();i++){
            int height = heights[i];
            int width = next[i]-prev[i]-1;
            int area = (long long) height*width ;
            maxarea = max(area,maxarea);
        }


        return maxarea;
    }
};