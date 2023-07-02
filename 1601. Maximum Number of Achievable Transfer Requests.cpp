class Solution {
public:

    int res = 0;
    // holds net changes in employees in n buildings
    vector<int> degree;

    void solve(int ind, vector<vector<int>>& requests, int cnt){
        if(ind == size(requests)){
            int fl = 0;
            // checking net change in employees
            for(int &val : degree) {
                if(val) {
                    fl = 1;
                    break;
                }
            }
            if(!fl) res = max(res, cnt);
            return;
        }

        // even after make all requests after current ind
        // if final_cnt < res
        // no point in checking further
        if(cnt + size(requests) - ind < res) return;

        // not pick
        solve(ind + 1, requests, cnt);

        // pick
        degree[requests[ind][0]]--;
        degree[requests[ind][1]]++;

        solve(ind + 1, requests, cnt + 1);

        degree[requests[ind][0]]++;
        degree[requests[ind][1]]--;
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        int s = size(requests);
        degree.resize(n);
        solve(0, requests, 0);
        return res;
    }
};