class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long long int x = 0;
        
        // Step 1: XOR all the elements in the array
        // XOR of all elements will be result in 3^4
        // 3^4 results in 7, its binary resentation is 0111.
        for(int i=0; i<n; i++){
            x ^= nums[i];
        }
           
        // Step 2: find the AND of x and 2s compliment of x
        // Now we need to check the bit at right most last but one 
        // column of every number, if it lies in 0 group or in 1 group.
        // To do so we need to retrieve a number, 
        // because XOR of all is 0111 and it consist both repeating and non repeating.
        // So to find two different groups we need that 
        // number which will help us to differentiate.
        // By doing bitwise AND of 0111 with its 2s compliment 1001,
        // we will get 0001. This will be the magical number which finds two groups.
        

        long long int y = (long long int)(x & -x);
        int g1=0, g2=0;
        

        // Step 3: Two groups of 0 and 1
        // 0 group : 1, 1, 4
        // 1 group : 2, 3, 2
        // By doing XOR we will get the answer 
        for(int i = 0; i<n; i++){
            if( (y & nums[i]) == 0){
                g1 ^= nums[i];
            }else{
                g2 ^= nums[i];
            }
        }
        vector<int> ans(2, 0);
        ans[0] = g1; ans[1] = g2;
        
        return ans;
    }
};