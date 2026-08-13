class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int len = cardPoints.size()-k;
        int sum = 0;
        for(int i=0;i<len;i++){
            sum+=cardPoints[i];
        }
        int low = 0;
        int high = len-1;
        int res = INT_MAX;
        while(low<cardPoints.size()&&high<cardPoints.size()){
            res = min(res,sum);

            sum-=cardPoints[low];
            low++;

            if(high==cardPoints.size()-1) break;
            high++;
            sum+=cardPoints[high];

        }

        int totalpoints = accumulate(cardPoints.begin(),cardPoints.end(),0);
        if(res ==INT_MAX) return totalpoints;
        return totalpoints-res;
    }
};