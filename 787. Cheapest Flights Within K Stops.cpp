class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {

        // Adjacency list - storing {next_node, price}
        vector<pair<int, int>> graph[n];
        for (auto &data : flights)  {
            graph[data[0]].push_back({data[1], data[2]});
        }

        // Queue for storing {stops, {node, price}}
        queue<pair<int, pair<int, int>>> q;
        // Vector for storing minimum_price for each node
        vector<int> minp(n, 1e9);      

        // Initalize
        q.push({0, {src, 0}}); 
        minp[src] = 0;

        while (!q.empty())
        {   
            // Current node
            int node = q.front().second.first;
            // Stops required to reach current_node from source
            int stops = q.front().first;        
            // Price required to reach current_node from source
            int price = q.front().second.second;
            q.pop();

            if (stops > K)  continue;   // No need for traversing
            
            // Adjacent nodes of current_node
            for (auto &x : graph[node])
            {
                // next_node or adjacent node to current_node
                int next = x.first;     
                // edge_weight or price required to reach next_node from current_node
                int weight = x.second; 

                // If (price from curr to next) + (price source to curr) < (minimum_pirce from source to next) 
                if ((weight + price < minp[next]) && (stops <= K))
                {
                    // Then update minimum_price for next_node
                    minp[next] = weight + price;
                    // And push next_node into the queue with stops+1 and minimum_price for next
                    q.push({stops + 1, {next, minp[next]}});
                }
            }
        }

        // If minimum_price from source to destination is infinity 
        // that means we cannnot reach destination so return -1 
        if (minp[dst] == 1e9) return -1;

        // otherwise return the minimum_price for destination
        return minp[dst];
    }
};