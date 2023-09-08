class Solution {
public:
     void findAns(vector<int>past,int numRows,vector<vector<int>>&ans,int &count){
          // base case
           int n=past.size();
          if(count==numRows){
              return ;
          }
         vector<int>temp;
         temp.push_back(past[0]);
         int pre=0;
         int curr=1;
         while(curr<=n-1){
             int r=past[pre]+past[curr];
             temp.push_back(r);
             pre=curr;
             curr=curr+1;
         } 
          temp.push_back(past[past.size()-1]);
           count++;
          ans.push_back(temp);
           findAns(temp,numRows,ans,count); 
     }
    vector<vector<int>> generate(int numRows) {
        vector<int>r1={1};
        vector<int>r2={1,1};
        if(numRows==1){
            return {r1};
        }
        if(numRows==2){
            return {r1,r2};
        }
         vector<vector<int>>ans;
          ans.push_back(r1);
          ans.push_back(r2);
          int count=2;
         findAns(r2,numRows,ans,count); 
           return ans;
    }
};