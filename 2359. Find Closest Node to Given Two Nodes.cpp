class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        const unsigned char VISITED1 = 1;
        const unsigned char VISITED2 = 2;
        const unsigned char VISITED_BOTH = VISITED1 | VISITED2;
        
        int n = edges.size();
        vector<unsigned char> visited(n);
        int result = n;
        
        // Both paths are still valid.  i.e. node1 and node2 are both valid node numbers.
        while (result == n && node1 >= 0 && node2 >= 0) {

            // Find next in path from node1.
            if ((visited[node1] & VISITED1) != 0) 
                node1 = -1;
            else if ((visited[node1] |= VISITED1) == VISITED_BOTH) 
                result = node1;
            else
                node1 = edges[node1];

            // Find next in path from node2.
            if ((visited[node2] & VISITED2) != 0) {
                node2 = -1;
                break;
            }
            if ((visited[node2] |= VISITED2) == VISITED_BOTH)
                return min(result, node2);
            node2 = edges[node2];
        }
        if (result != n)  return result;
        
        // If node1 still has a valid path, then node2 has reached the end of its path 
        // without intersecting the node1 path, so we only need to keep searching along 
        // the node1 path.
        if (node1 >= 0) {
            while (node1 >= 0) {
                if ((visited[node1] & VISITED1) != 0)  return -1;
                if ((visited[node1] |= VISITED1) == VISITED_BOTH)  return node1;
                node1 = edges[node1];
            }
            return -1;
        }
        
        // Node2 still has a valid path, then node1 has reached the end of its path 
        // without intersecting the node2 path, so we only need to keep searching along 
        // the node2 path.
        while (node2 >= 0) {
            if ((visited[node2] & VISITED2) != 0)  return -1;
            if ((visited[node2] |= VISITED2) == VISITED_BOTH)  return node2;
            node2 = edges[node2];
        }
        return -1;
    }
};