class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>>vec(n);
        for(int i = 0; i<roads.size(); i++){
            vec[roads[i][0]].insert(roads[i][1]);
            vec[roads[i][1]].insert(roads[i][0]);
        }
        int mx = 0;
        for(int i=0; i<n; i++){
            int sum = vec[i].size();
            for(int j=0; j<n; j++){
                if(j==i) continue;
                int val = sum + vec[j].size();
                if(vec[j].find(i)!=vec[j].end()) val--;
                mx = max(mx, val);
            }
        }
        return mx;
    }
};