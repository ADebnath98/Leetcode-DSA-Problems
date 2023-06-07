class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt = 0;

    while(c > 0 || a > 0 || b > 0){
        int ra = a%2 , rb = b%2 , rc = c%2;
        a/=2; b/=2; c/=2;
        if(rc == 1){
            if(ra == 1 || rb == 1)continue;
            cnt++;
        }
        else{
            if(ra == 1 && rb == 1)cnt+=2;
            else if(ra == 1 || rb == 1)cnt+=1;
        }
    }
    
    return cnt;
}
};