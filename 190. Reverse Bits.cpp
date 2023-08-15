class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t x = 1 ;
        int a = 0 ;
        int i = 32 ;
        while ( i != 0){
            a = (n & 1) ;
            n = n >> 1 ;
            if (a == 1){
                x = x<<1 ;
                x = (x | 1);
            }
            else {
                x = x << 1 ;
            }
            i--;
        }
        
        return x ; 
    }
};