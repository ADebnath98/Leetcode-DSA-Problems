Intuition
Approach
The algorithm first constructs the graph represented by the (edges) vector using an adjacency list in the graph vector, and counts the number of parents for each node in the (num_parents) vector. Then, it checks if there is a cycle in the graph using a recursive depth-first search with a (has_cycle) function. The (on_stack) vector is used to keep track of the nodes in the current recursion stack, and the (freq) vector is used to store the frequency of the colors in the nodes visited during the search.
If there is a cycle in the graph, the function returns -1, indicating that there is no valid path. Otherwise, the algorithm uses another recursive depth-first search with a (calc_freq) function to calculate the maximum frequency of a given color starting from each node with no parents. The freq vector is used to store the frequency of the color at each node, and the (max_freq) variable is used to keep track of the maximum frequency found so far.

Finally, the function returns the max_freq value, which represents the largest path value in the Directed Acyclic Graph with the given color constraints.

Complexity
Time complexity:
O(k*(V+E)) where k is number of distinct characters in string
Space complexity:
O(V+E)


class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> num_parents(n);
        vector<vector<int>> graph(n);
        vector<bool> on_stack(n, false);
        vector<int> freq(n, 0);

        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            num_parents[e[1]]++;
        }

        function<bool(int)> has_cycle = [&](int at) {
            if (freq[at] == 1) {
                return false;
            }
            if (on_stack[at]) {
                return true;
            }
            on_stack[at] = true;
            for (int to : graph[at]) {
                if (has_cycle(to)) {
                    return true;
                }
            }
            freq[at] = 1;
            on_stack[at] = false;
            return false;
        };

        function<int(int, char)> calc_freq = [&](int at, char c) {
            if (freq[at] != 0) {
                return freq[at];
            }

            int f = 0;
            for (int to : graph[at]) {
                f = max(f, calc_freq(to, c));
            }

            if (colors[at] == c) {
                f++;
            }
            freq[at] = f;
            return f;
        };

        for (int i = 0; i < n; i++) {
            if (has_cycle(i)) {
                return -1;
            }
        }

        int max_freq = -1;
        for (char c : unordered_set<char>(colors.begin(), colors.end())) {
            for (int i = 0; i < n; i++) {
                if (num_parents[i] == 0) {
                    freq.assign(n, 0);
                    max_freq = max(max_freq, calc_freq(i, c));
                }
            }
        }

        return max_freq;
    }
};
        