/*Intuition
The given problem is to find the minimum number of steps to reach the last index of the array, where in one step, we can either move to the adjacent indices or to any index having the same value as the current index.

The approach used to solve this problem is Breadth-First Search (BFS), where we start traversing the array from the first index, and at each step, we explore all the possible jumps that can be made from the current index. We keep track of the visited indices to avoid revisiting the same indices again, and we also maintain a queue to keep track of the indices that need to be explored in the next step.

Approach
For each index, we explore three possible jumps:

i + 1, where i + 1 < arr.length
i - 1, where i - 1 >= 0
j where arr[i] == arr[j] and i != j

If any of the next indices haven't been visited before, we mark them as visited and add them to the queue. We repeat this process until we reach the last index of the array or until there are no more indices to explore in the queue.

The minimum number of steps to reach the last index of the array is the number of steps required to reach the last index from the first index, which is the number of levels in the BFS tree.

Therefore, the intuition behind this approach is to explore all the possible jumps from each index of the array in a breadth-first manner until we reach the last index, and we maintain a count of the number of steps required to reach the last index.

Complexity
Time complexity:
The time complexity of the BFS algorithm used to solve this problem is O(n), where n is the number of elements in the array. This is because we visit each element of the array exactly once, and for each element, we explore at most three possible jumps.

Space complexity:
The space complexity of the algorithm is also O(n), as we need to store the visited array of size n and the queue of size at most n, which can happen in the worst case when all elements have the same value.*/


class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;
        unordered_map<int, vector<int>> indices;
        for (int i = 0; i < n; i++) {
            indices[arr[i]].push_back(i);
        }
        vector<int> visited(n);
        visited[0] = true;
        queue<int> q;
        q.push(0);
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();
                if (curr == n - 1) return steps;
                if (curr + 1 < n && !visited[curr + 1]) {
                    visited[curr + 1] = true;
                    q.push(curr + 1);
                }
                if (curr - 1 >= 0 && !visited[curr - 1]) {
                    visited[curr - 1] = true;
                    q.push(curr - 1);
                }
                for (int nextIndex : indices[arr[curr]]) {
                    if (nextIndex != curr && !visited[nextIndex]) {
                        visited[nextIndex] = true;
                        q.push(nextIndex);
                    }
                }
                indices[arr[curr]].clear();
            }
            steps++;
        }
        return -1;
    }
};