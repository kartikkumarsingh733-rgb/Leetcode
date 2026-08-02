class Solution {
public:
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};

    bool valid(int i,int j,int n,int m){
        if(i<0||i>=n||j<0||j>=m) return false;

        return true;
    }

    void dfs(vector<vector<char>> &grid,int i,int j,int n,int m,vector<vector<bool>> &vis){
        vis[i][j] = true;
        for(int k=0;k<4;k++){
            int row = i + x[k];
            int col = j + y[k];

            if(valid(row,col,n,m)&&grid[row][col]=='1'&&vis[row][col]==false){
                dfs(grid,row,col,n,m,vis);
            }
        }

        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int i;
        int j;
        int res = 0;
        vector<vector<bool>> vis(n,vector<bool>(m,0));

        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(grid[i][j]=='1'&&vis[i][j]==0){
                    dfs(grid,i,j,n,m,vis);
                    res++;
                }
            }
        }

        return res;
    }
};