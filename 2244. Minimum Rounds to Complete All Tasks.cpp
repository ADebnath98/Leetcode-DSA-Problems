class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        int count,ans=0;
        unordered_map<int, int>mp;
        for(int i=0; i<tasks.size(); i++){
            mp[tasks[i]]++;
        }
        for(auto it:mp){
            if(it.second>1)
            {if(it.second%3==0){
                ans+=it.second/3;
            }
            else if(it.second%3==1 || it.second%3==2){
                ans+=it.second/3+1;

            }}
            
            else{
                return -1;
            }
        }
        return ans;
    }
};