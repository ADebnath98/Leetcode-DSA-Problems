class Solution {
public:
    int ans;
    void solve(int curr,int curr_dis,vector<bool>&vis,vector<int>&dis,vector<int>&edges){
         
         if(curr!=-1){
             if(!vis[curr]){
                 vis[curr]=1,dis[curr]=curr_dis;
                 solve(edges[curr],curr_dis+1,vis,dis,edges);
             }
            else if(dis[curr]!=-1){
                 ans=max(ans,curr_dis-dis[curr]);
             }
             dis[curr]=-1;
         }
    }
    int longestCycle(vector<int>& edges) {
        vector<bool>vis(edges.size(),false);
        vector<int>dis(edges.size(),-1);
        int n=edges.size();
        ans=-1;
        for(int i=0;i<n;i++){
           if(!vis[i])solve(i,0,vis,dis,edges);
        }
        return ans;
    }
};