class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int j = num.size() - 1;
        int carry = 0;
        vector<int> ans;

        while (j >= 0 || k > 0 || carry > 0) {
            int dign = (j >= 0 ? num[j] : 0);
            int digk = k % 10;

            int sum = dign + digk + carry;
            ans.push_back(sum % 10);
            carry = sum / 10;

            k /= 10;
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};