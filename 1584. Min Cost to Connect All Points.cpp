Approach
treat the points as nodes of a complete graph when there is an edge between a node to every other node in the graph
use prims algorithm to find the cost of the minimum spanning tree of the above graph
Complexity
E = n*(n-1)/2 and V = n
Time complexity: E*log(V)
Space complexity: O(V)

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // prims algorithm
        int n = points.size();
        // min heap
        priority_queue <pair<int, int> , vector<pair<int, int>>, greater<pair<int,int>>> pq;        
        vector<int> vis(n, 0);
        // {dist, point(index of point in points array)}
        pq.push({0, 0}); // initiaize pq to the first index of points vector
        int sum = 0;
        while (!pq.empty()) {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            
            if (vis[node]) continue;
            // we add point/node to mst only when it is not visited
            vis[node]=1;
            sum += dist; // add the cost/dist
            // add all the unvisited points to the priority queue
            for (int i=0; i<n; i++) {
                if (!vis[i]) {
                    int val = abs(points[node][0] - points[i][0]) + abs(points[node][1] - points[i][1]); 
                    pq.push({val, i});
                }
            }
        }
        return sum;
    }
};