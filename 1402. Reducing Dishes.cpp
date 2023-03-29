class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        int n = s.size();
        sort(s.begin(),s.end());
        int ans = 0;

        ans = s[n-1];

        for(int i = 2;i<=n;i++){
            int c = 1;
            int cursum = 0;
            for(int j = n-i;j<n;j++){
                cursum += s[j]*c;
                c++;
            }

            ans = max(ans,cursum);
        }
        if(ans<0)
            ans = 0;
        return ans;
    }
};