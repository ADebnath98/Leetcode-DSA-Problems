class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph,  vector<int>& visited){
        for (auto i: graph[node]){
            if (visited[i]==0){
                visited[i] = visited[node]*-1;
                bool flag = dfs(i, graph, visited);
                if (!flag) return false;
            }
            else if (visited[i]==visited[node]) return false;
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(), 0);

        for (int i=0; i<graph.size(); i++){
            if (visited[i]==0){
                visited[i] = 1;
                bool flag = dfs(i, graph, visited);
                if (!flag) return false;
            }
        }

        return true;
    }
};