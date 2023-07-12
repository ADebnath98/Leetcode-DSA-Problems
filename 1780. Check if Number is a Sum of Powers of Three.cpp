class Solution {
public:
    bool checkPowersOfThree(int n) {
       for(int i=15;i>=0;i--){
           int num = pow(3,i);
           if(num <= n) n -= num;
       }

       return n == 0;
    }
};