class Solution {
public:
    bool res = true;

    void dfs(vector<vector<int>> &graph,int node,int c,vector<int> &color){
        color[node]=c;

        for(auto neigh:graph[node]){
            if(color[neigh]!=-1) {
                if(color[neigh]==c){
                    res = false;
                }
                
            }
            else{
                dfs(graph,neigh,1-c,color);
            }
        }

        return ;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        // if(graph.size()==1&&graph[0].size()==0) return true;
        vector<int> color(graph.size(),-1);
        // int first_node = -1;
        // for(int i=0;i<graph.size();i++){
        //     if(graph[i].size()>0){
        //         first_node = i;
        //         break;
        //     }
        // }
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1) dfs(graph,i,0,color);
        }
        

        return res;
    }
};