class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> mpp[26];
        int n=ideas.size();
        for(string& s:ideas)
        {
            mpp[s[0]-'a'].insert(s.substr(1));
        }
        long long ans=0;
        for(int i=0;i<26;i++)
        {
            for(int j=i+1;j<26;j++)
            {
                long long c1=0L,c2=0L;
                for(auto& c:mpp[i])
                {
                    if(mpp[j].count(c)==0)c1++;
                }
                for(auto& c:mpp[j])
                {
                    if(mpp[i].count(c)==0)c2++;
                }
                ans+=c1*c2;
            }
        }
        return ans*2;
        
    }
};