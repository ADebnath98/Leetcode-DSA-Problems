class Solution {
public:
    int partitionString(string s) {
          vector<int>ans(26,0) ;
          int count  = 1;
        //   ans[]
          for(int i = 0 ; i < s.size() ; i ++ ){              
            ans[s[i]- 'a'] ++; 
            if(ans[s[i]- 'a' ] ==2 ){
                count ++ ; 
                fill(ans.begin() , ans.end() , 0) ;
                ans[s[i] - 'a']++;
                continue ;
            }
          }
          return count ;
    }
};2405. Optimal Partition of String
