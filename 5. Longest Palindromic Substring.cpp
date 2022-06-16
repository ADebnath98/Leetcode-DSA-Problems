class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.length();
        
        if(n<=1) return s;
        
        int max_len = 1;
        int start  = 0, end = 0;
        
        for(int i=0;i<n-1;i++){
            
            int low = i,high = i;
            
            while(low>=0 && high < n){
                
                if(s[low] == s[high]){
                    low--;
                    high++;
                }else{
                    break;
                }
            }
            int len = high-low-1;
            
            if(len>max_len){
                max_len = len;
                start = low+1;
                end = high-1;
            }
        }
        
        for(int i=0;i<n-1;i++){
            
            int low = i,high = i+1;
            
            while(low>=0 && high < n){
                
                if(s[low] == s[high]){
                    low--;
                    high++;
                }else{
                    break;
                }
            }
            int len = high-low-1;
            
            if(len>max_len){
                max_len = len;
                start = low+1;
                end = high-1;
            }
        }
        return s.substr(start,max_len);
        
    }
};