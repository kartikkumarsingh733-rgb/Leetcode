class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        for (int next : asteroids) {
            bool destroyed = false;
            while (!stk.empty() && stk.top() > 0 && next < 0) {
                if (abs(stk.top()) < abs(next)) {
                    stk.pop(); // top asteroid destroyed
                    continue;  // keep checking with new top
                } else if (abs(stk.top()) == abs(next)) {
                    stk.pop(); // both destroyed
                }
                destroyed = true; // incoming asteroid destroyed
                break;
            }
            if (!destroyed) stk.push(next);
        }

        vector<int> res;
        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
