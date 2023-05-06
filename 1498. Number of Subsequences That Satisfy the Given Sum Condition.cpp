class Solution {
public:
    int numSubseq(vector<int>& v, int t) {
        int n=v.size();
        vector<int>pre{1};
        int mod=1e9+7;
        for(int i=1;i<=n;i++)
            pre.push_back((pre[i-1]<<1)%mod);
        sort(v.begin(),v.end());
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int x=t-v[i];
            int y=upper_bound(v.begin(),v.end(),x)-v.begin();
            //cout<<x<<" "<<y<<endl;
            if(y<=i)
                break;
            ans=(ans+pre[y-i-1])%mod;
        }
        return ans;
    }
};