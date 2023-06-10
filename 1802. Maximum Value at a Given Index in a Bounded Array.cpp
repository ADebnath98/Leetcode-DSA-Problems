Complexity
Time complexity:O(log(n))
Space complexity:O(1)

class Solution {
private:
    bool ispossible(int n, long long mid, int index, int maxSum){
        long long sum = mid;
        long long last,to_add;

        if(mid>index){
            last = mid-index;
            to_add = (mid*1ll*(mid-1))/2 - (last*1ll*(last-1))/2;
            sum += to_add;
        }
        else{
            last = index-mid+1;
            to_add = (mid*1ll*(mid-1))/2 + last;
            sum+=to_add;
        }
        if(n-index < mid){
            last = mid-(n-index)+1;
            to_add = (mid*1ll*(mid-1))/2 - (last*1ll*(last-1))/2;
            sum += to_add;
        }
        else{
            last = n-index-mid;
            to_add = (mid*1ll*(mid-1))/2 + last ;
            sum += to_add;
        }
        return sum<=maxSum;
    }
public:
    int maxValue(int n, int index, int maxSum) {
        long long low = 1;
        long long high = maxSum - n+1;
        long long ans = 1;
        while(low <= high){
            long long mid = low + (high - low)/2;
            // cout<<low<<" "<<high<<" "<<mid<<endl;
            if(ispossible(n,mid,index,maxSum)){
                ans = mid;
                // cout<<ans<<" ";
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};
// 4327190
// 4309968
// 798380516