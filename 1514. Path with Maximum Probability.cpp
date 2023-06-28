Time-Complexity -> O(N+ElogN) E-total edges
Space-Complexity -> O(N^2)



#define pd pair<int,double>
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pd> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        vector<double> maxP(n, 0);
        maxP[start]=1;
        priority_queue<pair<double,int>> q;
        q.push({1, start});
        
        while(!q.empty()){
            int node = q.top().second;
            double nodeProb = q.top().first;
            q.pop();
            
            for(auto it: adj[node]){
                int adjNode = it.first;
                double adjProb = it.second;
                
                if(nodeProb*adjProb > maxP[adjNode]){
                    maxP[adjNode] = nodeProb*adjProb;
                    q.push({maxP[adjNode], adjNode});
                }
            }
        }
        
        return maxP[end];
    }
};