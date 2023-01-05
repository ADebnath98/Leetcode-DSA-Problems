class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        int count = 1;
        int start = points[0][0];
        int end = points[0][1];
        for(int i = 1 ; i < n ;i++){
            if(points[i][0] < start || points[i][0] > end){
                end = points[i][1];
                count++;
            }else{
                start = points[i][0];
                end = min(end, points[i][1]);
            }
        }
        return count;












    //     map<int, int> mp;
    //     for(int i = 0 ; i < points.size() ; i++){
    //         mp[points[i][0]]++;
    //         mp[points[i][1]]--;
    //     }
    //     int ans = 0;
    //     int count = 0;
    //     for(auto el: mp){
    //         count += el.second;
    //         ans += count;
    //     }
    //     return ans;
    }
};