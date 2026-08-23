class Solution {
public:
    bool sumGame(string num) {
        int sumfirst_half = 0;
        int sumsecond_half = 0;
        int ques_first = 0;
        int ques_second = 0;

        int n = num.size();
        for (int i = 0; i < n; i++) {
            if (i < n / 2) {
                if (num[i] == '?') {
                    ques_first++;
                } else {
                    sumfirst_half += num[i] - '0';
                }
            } else {
                if (num[i] == '?') {
                    ques_second++;
                } else {
                    sumsecond_half += num[i] - '0';
                }
            }
        }


        if ((ques_first + ques_second) % 2 != 0) {
            return true;
        }

        
        return (2 * (sumfirst_half - sumsecond_half) != 9 * (ques_second - ques_first));
    }
};