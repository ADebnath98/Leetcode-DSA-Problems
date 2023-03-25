APPROACH :
What we need to find :

We need to find the total no of pairs of nodes which are not connected.

Assumption :
if we assume that all nodes are connected , then total pairs are n*(n-1)/2.

Logic :
Since we know that all pairs are not connected , to find the left out pairs , we need subtract the pair which are connected from total number of pairs.

To find the pair which are connected we need to find the no.of nodes in each component.

In a singe component if there are k nodes there are k*(k-1)/2 connected pairs.

So now we can generalise this for 'm' components.



class Solution {
public:
   void count_nodes(int i,vector<bool>&visited, unordered_map<int,vector<int>>&graph,int&nodes)
    {
        if(!visited[i])
        {
            nodes++;
            visited[i]=1;
            for(auto it : graph[i])
            {
                count_nodes(it,visited,graph,nodes);
            }
        }

    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> count;
        unordered_map<int,vector<int>> graph;
        vector<bool> visited(n,0);
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                int nodes=0;
                count_nodes(i,visited,graph,nodes); /* gives the count of the nodes in the a component */
                
                count.push_back(nodes);
            }
        }
        
        long long ans= (long long) n*(n-1)/2;  /*Total no of pairs*/
        for(int i=0;i<count.size();i++)
        {
            ans-=(long long) count[i]*(count[i]-1)/2;  /*Removing pairs present in the component */ 
        }
        return ans /*return the left out pairs*/;

    }
};