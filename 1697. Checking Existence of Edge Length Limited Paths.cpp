Approach
Define two structures Query and Edge, representing a query and an edge in the graph, respectively. Query contains the source node, destination node, maximum distance limit, and the query index. Edge contains the source node, destination node, and edge weight (distance).

Define two comparison functions cmp_query and cmp_edge to compare Query and Edge structures, respectively, based on their distance. These will be used to sort the queries and edges later.

Define a find function that finds the root of a given node using the union-find algorithm. It iteratively traverses the parent nodes until it reaches the root of the component.

Define a uni function that merges two nodes using the union-find algorithm. It first finds the roots of the nodes, and if they are different, it merges the smaller component to the larger one.

Define the main function distanceLimitedPathsExist that takes the number of nodes n, the edge list, and the queries as input and returns a vector of boolean values as output.

Create an empty vector of boolean values ans with the size of the number of queries.

Sort the queries in ascending order of their maximum distance limit using the cmp_query function.

Sort the edges in ascending order of their weight (distance) using the cmp_edge function.

Create two vectors, parent and size, of size n, and initialize each element of parent to its index (i.e., parent[i]=i) and each element of size to 1.

Iterate over the sorted queries, and for each query:

a. Add edges to the MST until the distance limit of the current query is reached. To do this, iterate over the sorted edges from the current position until an edge is encountered with a weight greater than the maximum distance limit of the current query. For each edge, use the uni function to merge the nodes of the edge if they are not already in the same component.

b. Check if the source and destination nodes of the query are in the same component using the find function, and set the corresponding value in ans to true if they are, false otherwise.

Return ans as the output of the function.

Complexity
Time complexity: O((M+N)logN) where M is number of edges and N is number of nodes in the graph

Space complexity: O(N+M+Q) where Q is number of queries, and M and N as mentioned above




class Solution {
	public:
		struct Query {
			int u, v, dist, idx;
		};
		struct Edge {
			int u, v, dist;
		};
		static bool cmp_query(const Query& q1, const Query& q2) {
			return q1.dist < q2.dist;
		}
		static bool cmp_edge(const Edge& e1, const Edge& e2) {
			return e1.dist < e2.dist;
		}
		int find(int v, vector<int>& parent) {
			int root = v;
			while (root != parent[root]) {
				root = parent[root];
			}
			while (v != root) {
				int next = parent[v];
				parent[v] = root;
				v = next;
			}
			return root;
		}
		void uni(int u, int v, vector<int>& parent, vector<int>& size) {
			int root_u = find(u, parent);
			int root_v = find(v, parent);
			if (root_u != root_v) {
				if (size[root_u] > size[root_v]) {
					parent[root_v] = root_u;
					size[root_u] += size[root_v];
				} else {
					parent[root_u] = root_v;
					size[root_v] += size[root_u];
				}
			}
		}
		vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
			vector<bool> ans(queries.size());
			vector<Query> sorted_queries;
			for (int i = 0; i < queries.size(); i++) {
				sorted_queries.push_back({queries[i][0], queries[i][1], queries[i][2], i});
			}
			sort(sorted_queries.begin(), sorted_queries.end(), cmp_query);
			vector<Edge> sorted_edges;
			for (int i = 0; i < edgeList.size(); i++) {
				sorted_edges.push_back({edgeList[i][0], edgeList[i][1], edgeList[i][2]});
			}
			sort(sorted_edges.begin(), sorted_edges.end(), cmp_edge);
			vector<int> parent(n);
			vector<int> size(n, 1);
			for (int i = 0; i < n; i++) {
				parent[i] = i;
			}
			int j = 0;
			for (const auto& query : sorted_queries) {
				while (j < sorted_edges.size() && sorted_edges[j].dist < query.dist) {
					uni(sorted_edges[j].u, sorted_edges[j].v, parent, size);
					j++;
				}
				int root_u = find(query.u, parent);
				int root_v = find(query.v, parent);
				ans[query.idx] = (root_u == root_v);
			}
			return ans;
		}
	};