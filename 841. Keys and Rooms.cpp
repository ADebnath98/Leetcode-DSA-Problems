class Solution {
public:

    // Function to perform the DFS traversal
    void dfs(vector<vector<int>> &rooms, vector<bool> &viz, int* count, int curr){
        for(auto i: rooms[curr]){
            // Check if the key found in the room has already been visited or not. If visited already, then don't do anything otherwise...
            if(!viz[i]){
                // Mark this as visited
                viz[i] = true;
                // Increment the count
                *count = *count + 1;
                // And then do dfs on this particular room
                dfs(rooms, viz, count, i);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // Number of rooms
        int n = rooms.size();
        // // boolean array to track if a node has been visited already or not. It true then it has been visited, else not.
        vector<bool> viz(n, false);
        // Since we will start from 0th room so we'll mark 0th as visited.
        viz[0] = true;
        // Counter to count number of rooms visited, it is initialized to 1 because we are already inside the 0th room.
        int count = 1;
        // Call the dfs function by supplying appropriate paramenters.
        dfs(rooms, viz, &count, 0);
        // Return the result
        return count == n;
    }
};