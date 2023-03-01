

class Solution {
public:
   void mergesort(vector<int> &nums,int start,int end){
        if(end-start+1<=1) return;
        int mid=start+(end-start)/2;
        mergesort(nums,start,mid);
        mergesort(nums,mid+1,end);
        merge(nums,start,mid,end);
    }
    void merge(vector<int> &nums,int start,int mid,int end){
        int lp=start;
        int rp=mid+1;
        int size=end-start+1;
        vector<int> buff(size,0);
        int bp=0;
        while(lp<=mid && rp<=end){
            if(nums[lp]<nums[rp]){
                buff[bp++]=nums[lp++];
            }
            else{
                buff[bp++]=nums[rp++];
            }
        }
        while(lp<=mid){buff[bp++]=nums[lp++];} 
        while(rp<=end){buff[bp++]=nums[rp++];} 
        for(int i=0;i<=buff.size()-1;i++){
            nums[i+start]=buff[i];
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int N=nums.size();
        mergesort(nums,0,N-1);
        return nums;
    }
    
};