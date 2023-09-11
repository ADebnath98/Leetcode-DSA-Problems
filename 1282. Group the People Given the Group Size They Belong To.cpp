class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>> map;
        vector<vector<int>> vc;
        int n = groupSizes.size();
        for(int i = 0 ; i < n ; i ++){
            map[groupSizes[i]].push_back(i);
            if(map[groupSizes[i]].size() == groupSizes[i]){
                vc.push_back(map[groupSizes[i]]);
                map[groupSizes[i]].clear();
            }
        }
        return vc;
    }
};