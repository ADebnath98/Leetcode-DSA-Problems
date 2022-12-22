class Solution {
public:
    void subtreeNodes(int root,int n,vector<vector<int>>& graph,int parent,vector<int>& nodes)
    {
        int numNodes = 0;
        for(int i =0;i < graph[root].size();i++)
        {
            if(graph[root][i] != parent)
            {
                subtreeNodes(graph[root][i],n,graph,root,nodes);
                numNodes += nodes[graph[root][i]];
            }
        }
        numNodes++;
        nodes[root] = numNodes;
    }
    void fillDistance(vector<vector<int>>& graph,int n,int root,int parent,vector<int>& nodes,vector<int>& answer)
    {
        if(parent != -1)
        {
            answer[root] = answer[parent] - 2*nodes[root] + n;
        }
        for(int neighbour : graph[root])
        {
            if(neighbour != parent)
            {
                fillDistance(graph,n,neighbour,root,nodes,answer);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        // start at a root and calculate the number of nodes in each subtree root
        // then on moving on to the children we add subtract the number of nodes in that subtree and 
        // we add the remaining ones(n- subtree nodes)
        vector<vector<int>>  graph(n,vector<int> ());
        for(auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> nodes(n,-1);
        subtreeNodes(0,n,graph,-1,nodes);
        vector<int> answer(n,-1);
        int sumNode = 0;
        vector<int> stack {0};
        set<int> visited {0};
        vector<int> distance(n,0);

        while(stack.size()>0)
        {
            int top = stack[stack.size()-1];
            stack.pop_back();
            for(int neighbour : graph[top])
            {
                if(visited.count(neighbour) == 0)
                {
                    distance[neighbour] = 1 + distance[top];
                    sumNode += distance[neighbour];
                    visited.insert(neighbour);
                    stack.push_back(neighbour);
                }
            }
        }
        answer[0] = sumNode;
        fillDistance(graph,n,0,-1,nodes,answer);
        return answer;

    }
};