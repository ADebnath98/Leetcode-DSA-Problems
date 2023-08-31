class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // to store start & end point a tap can water
        vector<pair<int, int>> v(n+1);
        for(int i=0; i<=n; i++){
            v[i].first = max(0, i-ranges[i]);
            v[i].second = min(n, i+ranges[i]);
            // cout<<v[i].first<<v[i].second<<endl;
        }
        // to store start_point as index and max end_point for given start as value
        vector<int> start_end(n+1, 0);
        for(auto it:v){
            int start = it.first;
            int end = it.second;
            if(start_end[start]<end) start_end[start] = end;
        }
        // for(auto it:start_end) cout<<it<<" ";
        // transverse and check the need
        int curr_end=0, max_end=0, taps=0;
        for(int i=0; i<=n; i++){
            if(i>max_end) return -1;
            if(i>curr_end){
                taps++;
                curr_end = max_end;
                if(curr_end==n) return taps;
            }
            max_end = max(max_end, start_end[i]);
        }
        return -1;
    }
};