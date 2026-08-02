class Solution {
public:
    void dfs(vector<vector<int>>& a, int i, int n, vector<bool>& vis) {
        vis[i] = true;
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1 && !vis[j]) {
                dfs(a, j, n, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int res = 0;
        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(isConnected, i, n, vis);
                res++;
            }
        }
        return res;
    }
};
