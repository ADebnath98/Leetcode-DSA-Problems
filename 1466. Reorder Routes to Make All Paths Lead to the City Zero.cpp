class Solution {
public:
    int minReorder(int n, vector<vector<int>>& c) {

        vector<int> adj[n];


        vector<int> in[n];
        vector<int> out[n];

        for(int i=0;i<c.size();i++)
        {
            out[c[i][0]].push_back(c[i][1]);
            in[c[i][1]].push_back(c[i][0]);
        }

        queue<int> q;
        q.push(0);
        int count =0;
        vector<int> vis(n , 0);
        while(!q.empty())
        {
            int x = q.front();
            q.pop();

            for(auto it : out[x])
            {
                if(vis[it]==1)
                continue;

                count++;
                q.push(it);

                    
            }
            for(auto it : in[x])
            {
                if(vis[it]==1)
                continue;
                q.push(it);
            }
            vis[x]=1;
        }
        return count;

    }
};