class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<bool>> vis(1<<n,vector<bool>(n));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            vis[1<<i][i]=1;
            q.push({1<<i,i});
        }
        int steps=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int currmask=q.front().first;
                int currnode=q.front().second;
                q.pop();
                if(currmask==((1<<n)-1))return steps;

                for(int adj:graph[currnode]){
                    int adjmask=(currmask | 1<<adj);
                    if(vis[adjmask][adj])continue;
                    vis[adjmask][adj]=1;
                    q.push({adjmask,adj});
                }
            }
            steps++;
    }
    return -1;


    }
};