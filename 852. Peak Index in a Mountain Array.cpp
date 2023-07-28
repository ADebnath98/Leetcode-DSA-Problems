class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) { 
        int start=0,mid=0,last=arr.size()-1;
        while(start<last)
        {
            mid=(last-start)/2+start;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
            {
                return mid;
            }
            else if(arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1])
            {
                start=mid;
            }
            else
            {
                last=mid;
            }
        }  
        return mid;;
    }
};