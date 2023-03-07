class Solution {
    int Trips(long long mid, vector<int>& time, int totalTrips)
    {
        long long n = time.size(), ans = 0;
        for(int &num : time)
            ans += mid/num;
        if(ans >= totalTrips)
            return true;
        return false;
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int m = time.size();
        long long i = 1, ans = 0;
        long long j = (long long)time[0]*totalTrips;
        while(i <= j)
        {
            long long mid = i + (j-i)/2;
            if(Trips(mid, time, totalTrips))
            {
                ans = mid;
                j = mid-1;
            }
            else
            {
                i = mid+1;
            }
        }
        return ans;
    }
};