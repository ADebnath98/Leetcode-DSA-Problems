class Solution {
public:
    int fib(int n) {
        
        if(n==0)
        return 0;
    if(n==1)
        return 1;
    int a = 1,b=1;
    for (int i = 2; i < n; ++i) {
        int fib = a+b;
        a=b;
        b=fib;
    }

    return b;
    }
};