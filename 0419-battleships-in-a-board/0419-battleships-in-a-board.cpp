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
    void dfs(vector<vector<char>>& board,int m,int n,int i,int j,vector<vector<bool>> &vis){
        vis[i][j]=true;

        for(int k=0;k<4;k++){
            int row = i + x[k];
            int col = j + y[k];

            if(valid(m,n,row,col)&&board[row][col]=='X'&&vis[row][col]==0){
                dfs(board,m,n,row,col,vis);
            }
        }

    }
    int countBattleships(vector<vector<char>>& board) {
        int res = 0;
        vector<vector<bool>> vis(board.size(),vector<bool>(board[0].size(),false));
        int m = board.size();
        int n = board[0].size();

        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j]=='X'&&vis[i][j]==false){
                    dfs(board,m,n,i,j,vis);
                    res++;
                }
            }
        }


        return res;
    }
};