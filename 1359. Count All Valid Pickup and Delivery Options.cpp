class Solution {
public:
    int mod=1e9+7;
    int countOrders(int n) {
        vector<long long>prefix(n,0);
        prefix[0]=1;
        for(int i=1;i<n;i++)
        {
            prefix[i]=((2*i+1)*(i+1)*prefix[i-1])%mod;
        }
        return prefix[n-1];
    }
};