class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        int n=nums.size();

        int res=INT_MAX;

        priority_queue<int> pq;

        int mini=INT_MAX;

        for(int i=0;i<n;i++){
            //if even
            if(nums[i]%2==0){
                pq.push(nums[i]);
                mini=min(mini,nums[i]);
            }
            //if odd
            else{
              pq.push(nums[i]*2);
              mini=min(mini,nums[i]*2);
            }
        }

        while(!pq.empty()){
             
             int top=pq.top();
             pq.pop();

             res=min(res,top-mini);
             //if top element is odd then we can break
             if(top%2!=0){
               break;
             }

             mini=min(mini,top/2);
             pq.push(top/2);
        }

        return res;
    }
};