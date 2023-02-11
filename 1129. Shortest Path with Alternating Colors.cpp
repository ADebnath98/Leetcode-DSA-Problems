/*Intuition :
Here we are given a graph with two types of edges (red and blue), the goal is to find the shortest path from node 0 to every other node such that no two consecutive edges have the same color.
Explanation to Approach :
So we are using a breadth-first search (BFS) algorithm to traverse the graph, keeping track of the distance from node 0 to every other node and the previous edge color.
The graph is represented as an adjacency list, where graph[u] is a list of pairs (v, edgeColor) representing an edge from node u to node v with color edgeColor.
The BFS algorithm starts from node 0 and adds node v to the queue if it is not visited yet or if the color of the edge from u to v is different from the previous edge color.
The distance from node 0 to node v is incremented in each step.
The ans array is updated with the minimum distance found so far to each node. If a node is visited again, its distance in ans is not updated.
The algorithm terminates when the queue is empty, meaning that all reachable nodes have been visited.
If a node is not visited, its distance in ans remains -1, indicating that it is not reachable from node 0.
Complexity :
Time complexity : O(n)
Space complexity : O(n)*/

enum class Color { kInit, kRed, kBlue };

class Solution {
 public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges,
                                       vector<vector<int>>& blueEdges) {
    vector<int> ans(n, -1);
    vector<vector<pair<int, Color>>> graph(n);  // graph[u] := [(v, edgeColor)]
    queue<pair<int, Color>> q{{{0, Color::kInit}}};  // [(u, prevColor)]

    for (const vector<int>& edge : redEdges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].emplace_back(v, Color::kRed);
    }

    for (const vector<int>& edge : blueEdges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].emplace_back(v, Color::kBlue);
    }

    for (int step = 0; !q.empty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        const auto [u, prevColor] = q.front();
        q.pop();
        ans[u] = ans[u] == -1 ? step : ans[u];
        for (auto& [v, edgeColor] : graph[u]) {
          if (v == -1 || edgeColor == prevColor)
            continue;
          q.emplace(v, edgeColor);
          v = -1;  // Mark (u, v) as used.
        }
      }

    return ans;
  }
};