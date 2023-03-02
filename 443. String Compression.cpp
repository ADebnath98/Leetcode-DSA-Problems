class Solution {
public:
    int compress(vector<char>& chars) {
        string res ; 
        int count = 1,i ; 
        
        for(  i = 1; i<chars.size();i++)
        {
            if(chars[i]!=chars[i-1])
            {
            res = res + chars[i-1];
            if(count!=1)
              {
                res = res + to_string(count);
              }
              count = 1; 
            
            }
            else count++; 

        }
        
        res = res + chars[chars.size()-1] ; 
        if(count!=1)
        res += to_string(count);
         
   
       for(int i = 0 ; i<res.size();i++)
       chars[i] = res[i] ; 
      
      return res.size();

      
        
    }
};