class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> mp;
        for(int i=0; i<grid.size(); i++){
            vector<int> k;
            for(int j=0; j<grid[i].size(); j++){
                k.push_back(grid[i][j]);
            }
            mp[k]++;
        }
        int cnt=0;
        for(int i=0; i<grid[0].size(); i++){
            vector<int> k;
            for(int j=0; j<grid.size(); j++){
                k.push_back(grid[j][i]);
            }
            if(mp.find(k)!=mp.end()){
                cnt+=mp[k];
            }
        }
        return cnt;
    }
};