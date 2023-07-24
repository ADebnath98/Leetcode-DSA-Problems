Intuition
Treat n in terms of binary representation.

Approach
Divide n by 2 in each loop to gets the next LSB. of n.
Solve for the Least significant Bits of n.
compute square of x in each loop.
if(it is 1)multiply the current x to it;


class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)return 1;
        long b = abs(n);        
        double d =1;
        while(b){
            if(b&1)d=d*x;
            x=x*x;
            b= b/2;
        }
        if(n<0)d = 1/d;
        return d;       
    }
};