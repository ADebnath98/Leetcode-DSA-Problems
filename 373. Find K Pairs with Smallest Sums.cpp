class Solution {
public:
        vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k){
              //base case
              vector<vector<int>> res; 

              if(nums1.size() == 0 || nums2.size() == 0) return res;

              priority_queue< pair<int, pair<int,int>>> pq;

              //insert vectors for each pair sum in map  
              for(int i=0;i<nums1.size();i++){
                for(int j=0; j<nums2.size() ;j++){

                  int sum = nums1[i] + nums2[j];

                  if(pq.size() < k)
                    pq.push({sum,{nums1[i],nums2[j]}});

                  else if(sum < pq.top().first){

                        pq.pop();
                        pq.push({sum,{nums1[i],nums2[j]}});
                   }
                  else break; 
              }
          }

              //insert top kth map keys value in answer  
              while( !pq.empty() ){

                 res.push_back({pq.top().second.first , pq.top().second.second});
                 pq.pop();

              }

              return res;
        }
};