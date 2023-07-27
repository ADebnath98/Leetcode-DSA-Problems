class Solution {

    bool valid(vector<int>& b, int n, long time)
    {
        long sum=0;
        for(int bat:b) sum+=min(static_cast<long>(bat), time);
        return (sum>=static_cast<long>(time)*n);
    }
public:
    long long maxRunTime(int n, vector<int>& btrs) {
        long powsum=0;
        for(int p:btrs) powsum+=p;
        long l=1, r=powsum/n;
        while(l<r)
        {
            long time=(l+r+1)/2; //+1 to ensure time rounds up in case of fractional value
            if(valid(btrs,n,time)) l=time;
            else r=time-1;
        }
        return l;
    }
};