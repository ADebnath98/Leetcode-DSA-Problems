class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) 
    {
       //we will create a path using bfs and then we will take minimum value among the path value
        vector<vector<int>> adjNodes[n+1];
        for(int i=0;i<roads.size();i++)
        {
            adjNodes[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adjNodes[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }

        vector<bool> mark(n+1,false);
        mark[1] = true;                                 
        
        // bfs
        queue<int> que;
        que.push(1);

        while(!que.empty())
        {
            int node = que.front();
            que.pop();

            for(auto &it : adjNodes[node])
            {
                if(!mark[it[0]])
                {
                    mark[it[0]] = true;
                    que.push(it[0]);
                }
            }
        }
        int mn = INT_MAX;
        for(int i=0;i<roads.size();i++)
        {
            if(mark[roads[i][0]] && mark[roads[i][1]])
            {
                mn = min(mn,roads[i][2]);
            }
        }

        return mn;
    }
};