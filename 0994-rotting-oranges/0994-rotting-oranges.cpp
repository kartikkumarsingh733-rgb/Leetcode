class Solution {
public:
    int time = 0;
    int fresh = 0;
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};
    bool valid(int m,int n,int row,int col){
        if(row<0||row>=m||col<0||col>=n) return false;

        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    grid[i][j]=-2;
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        while(!q.empty()&&fresh>0){
            int lvlsize = q.size();
            time ++;
            while(lvlsize--){
                auto it = q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int row = it.first + x[k];
                    int col = it.second + y[k];
                    if(valid(grid.size(),grid[0].size(),row,col)&&grid[row][col]==1){
                        q.push({row,col});
                        grid[row][col]=-2;
                        fresh--;
                    }
                }

            }
        }
        if(fresh>0) return -1;
        return time;
    }
};