class Solution {
public:
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};
    bool valid(int row,int col,int i,int j){
        if(i<0||i>=row||j<0||j>=col){
            return false;
        }

        return true;
    }

    void dfs(vector<vector<char>>& grid,int m,int n,int i,int j,vector<vector<bool>> &vis){
        vis[i][j]=true;

        for(int k=0;k<4;k++){
            int row = i + x[k];
            int col = j + y[k];

            if(valid(m,n,row,col)&&grid[row][col]=='1'&&vis[row][col]==0){
                dfs(grid,m,n,row,col,vis);
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]=='1'&&vis[i][j]==false){
                    dfs(grid,m,n,i,j,vis);
                    res++;
                }
            }
        }


        return res;

    }
};