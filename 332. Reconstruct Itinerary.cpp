class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> graph;
        vector<string> itinerary;
        
        // Build the graph
        for (const auto& ticket : tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }
        
        // Start the DFS from JFK
        dfs("JFK", graph, itinerary);
        
        // Reverse the itinerary to get the correct order
        reverse(itinerary.begin(), itinerary.end());
        
        return itinerary;
    }
    
    void dfs(string airport, unordered_map<string, multiset<string>>& graph, vector<string>& itinerary) {
        while (!graph[airport].empty()) {
            string nextAirport = *graph[airport].begin();
            graph[airport].erase(graph[airport].begin());
            dfs(nextAirport, graph, itinerary);
        }
        itinerary.push_back(airport);
    }
};





