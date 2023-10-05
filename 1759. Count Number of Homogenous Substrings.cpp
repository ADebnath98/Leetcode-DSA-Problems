class Solution {
public:
    int countHomogenous(string s) {
      const unsigned int M = 1000000007;
    int n=1;
    int t=1;
    int prev=s[0];
    for(int i=1;i<s.size();i++)
    {
       if(s[i]==prev)
       {t++;}
       else
       { t=1; prev=s[i];}
        
        n+=t;
        n=n%M;
    }
    
    return n;  
    }
};