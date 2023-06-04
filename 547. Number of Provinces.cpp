class Solution {
public:
    void dfs(int ind,vector<vector<int>>& graph,vector<int>& vis){
         vis[ind]=1;
         int n = graph.size();
         for(int i=0;i<n;i++){
             if(graph[ind][i]==1 && vis[i]==0){
                 dfs(i,graph,vis);
             }
         }
    }
    int findCircleNum(vector<vector<int>>& graph) {
        int n=graph.size();
        int cnt = 0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,graph,vis);
                cnt++;
            }
        }
        return cnt;
    }
};