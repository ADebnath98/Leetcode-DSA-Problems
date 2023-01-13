class Solution {
    vector<vector<int>> adj;
    int ans = 1;

    int len(string &s, int i)
    {
        if (adj[i].empty()) return 1;
        int l1 = 0, l2 = 0;

        for (auto &c : adj[i])
        {
            int l = len(s, c);
            ans = max(ans, l);

            if (s[i] == s[c]) continue;
            
            if (l > l1)
            {
                l2 = l1;
                l1 = l;
            } else l2 = max(l2, l);
        }
        ans = max(ans, l1 + l2 + 1);
        return 1 + l1;
    }

public:
    int longestPath(vector<int>& parent, string s) {
        adj.resize(parent.size());
        for (int i = 1; i < parent.size(); ++i)
            adj[parent[i]].push_back(i);
        len(s, 0);
        return ans;
    }
};