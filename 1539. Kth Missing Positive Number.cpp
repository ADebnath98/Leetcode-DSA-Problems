class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int t=1, last=arr.back(),idx=0;
        for(int i=1;i<=last;i++){
            if(arr[idx]!=i){
                k--;
                if(k==0) return i;
            }
            else
             idx++;
        }
        return last+k;
    }
};