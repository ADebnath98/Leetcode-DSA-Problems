class Solution {
public:
    bool buddyStrings(string s, string goal) {
            if(s.length()!=goal.length())
        return false;
    
    int ans=0;
    if(s==goal)
    {
        map<char,int>mp;
        for(auto it:s)
        {
            mp[it]++;
            if(mp[it]>1)
                return true;
        }
        return false;
    }
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=goal[i])
            ans++;
    }
    if(ans>2)
        return false;
    else
    {
        int i=0,j=s.length()-1;
        while(i<s.length()&&s[i]==goal[i])
            i++;
         while(j>0&&s[j]==goal[j])
            j--;
        
        if(s[i]!=goal[j]||s[j]!=goal[i])
            return false;
        else
            return true;
        
    }
        
}
    
};