class Solution {
public:
    int dfs(int root, vector<vector<int>> &g, vector<int> &vis, vector<int> &nodeCount, long long &ans, int &seats){
        vis[root] = 1;
        for(auto i: g[root]){
            if(vis[i] != 1)  nodeCount[root] += dfs(i, g, vis, nodeCount, ans, seats);
        }
        if(root != 0 ){
            ans += nodeCount[root]/seats;
            if(nodeCount[root] % seats ) ans = ans + 1;
        }
        return nodeCount[root];
    }
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        long long ans = 0;
        int n = roads.size() + 1;
        vector<vector<int>> g(n);
        vector<int> vis(n, -1);
        vector<int> nodeCount(n, 1);2477. Minimum Fuel Cost to Report to the Capital

        for(auto r: roads){
            g[r[0]].push_back(r[1]);
            g[r[1]].push_back(r[0]);
        }
        dfs(0, g, vis, nodeCount, ans, seats);
        return ans;
    }
};