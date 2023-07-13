Approach
I have used BFS or Kahn's algorithm for topological sort here

Create an adjacency list and indegree vector for all the nodes(courses). Indegree vector shows that how many other courses the given course is dependent on.
Push all the nodes with 0 indegree into the queue
use a queue to implement BFS
for every node that you visit(pop from the queue) remove it from graph by decreasing indegree of its adjacent nodes.
again add nodes which have 0 indgree and repeat steps.
In the end if we were able to visit every node once then return true else return false.
Complexity
Time complexity: O(V+E)

Space complexity: O(V)

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);
        for(auto &i:prerequisites){
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        int c=0;
        while(!q.empty()){
            auto node=q.front();
            c++;
            q.pop();
            for(auto i:adj[node]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        if(c==n) return true;
        return false;
    }
};