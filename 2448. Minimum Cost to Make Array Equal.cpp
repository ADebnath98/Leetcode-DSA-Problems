Intuition
Use Binary Search implementation .

Complexity
Time complexity:
O(n∗logn)O(n*logn)O(n∗logn)

Space complexity:
O(1)O(1)O(1)




class Solution {
public:
 typedef long long ll;
    long long findCost(vector<int>&nums,vector<int>&cost, int target){
              ll res =0;
              for(int i=0;i<nums.size();++i){
                  res+= (ll)abs(nums[i]-target)*cost[i];
              }
              return res;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
              ll ans=INT_MAX;
              int left= *min_element(nums.begin(),nums.end());
              int right= *max_element(nums.begin(),nums.end());
           while(left<=right){
               int mid = left + (right -left )/2;
               ll cost1 = findCost(nums,cost,mid);
               ll cost2 =findCost(nums,cost,mid+1);
               ans = min(cost1,cost2);
              if(cost2>cost1){
                   right =mid-1;
              }else{
                   left=mid+1;
              }
           }
           return ans==INT_MAX ? 0 : ans;
    }
};