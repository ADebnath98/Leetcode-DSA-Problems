Intuition
We have a property that x & (x-1) flips the rightmost bit in x to 0, so we can observe that x & (x-1) have one set bit less than x, so think of how we can use this property.

You can easily come up with log(n) solution for each i value starting from 0-n, resulting in nlog(n) complexity but try to reduce this to even further n

Approach
To do it in O(n) we can use the answer of previous values like
when we are calculating ans for some value, lets say x. calculate value of x & x-1, you know that answer of x & x-1 is always one less than ans for x, so in this way you can proceed, this is a kind of dynamic programming, avoing repetitive computation.

Complexity
Time complexity: O(n)

Space complexity: O(n)


class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 0;
        for(int i=1;i<=n;i++){
           dp[i] = dp[i&(i-1)] + 1;
        }
       return dp;
    }
};