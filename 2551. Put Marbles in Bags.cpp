class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        //Approach
        //On observation we find that first and last indices will always be included irrespective of how we divide the marbles
        //Now we need to put k-1 dividers in n-1 gaps present
        //we observe that if we put the divider at the ith gap numbers i and i+1 will get included in the sum as they are now the corners of their group
        //using this fact we can see that we only need to count the maximum and minimum of those dividers
        //Now let's see the code
        --k;//as we need to make k-1 cuts in the array
        int n = weights.size();
        for(int i=0;i<n-1;i++){
            weights[i] += weights[i+1];//update the array to contain the value if we place a divider here
        }
        weights.pop_back();//as last value can't be divided
        
        //now the task is simple to find the top/bottom k-1 (here k as already reduced k) elements
        //that can be done either by sorting or by using pq
        //here i have used pq
        
        
        priority_queue<int> pq1;//max_heap(this will contain k smallest elements at the end)
        priority_queue<int,vector<int>,greater<int>> pq2;//min_heap(this will contain k largest elements at the end)
        for(auto x:weights){
            pq1.push(x);
            pq2.push(x);
            if(pq1.size()>k)
                pq1.pop();//pop the largest element if size becomes > k
            if(pq2.size()>k)
                pq2.pop();//pop the smallest element if size becomes > k
        }
        long long maxi=0,mini=0;
        for(int i=0;i<k;i++){
            maxi += 1L*pq2.top();pq2.pop();
            mini += 1L*pq1.top();pq1.pop();
        }
        return maxi-mini;
    }
};