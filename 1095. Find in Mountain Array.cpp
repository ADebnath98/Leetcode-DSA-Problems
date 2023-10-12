/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
int binarysearch(int low, int high, int target, MountainArray &mountainArr, bool increasing)
{
    while(low != high)
    {
        int mid = low + (high-low)/2 ;
        if(!increasing)
        {
            if(mountainArr.get(mid) > target)
                low=mid+1;
            else
                high = mid;
        }
        else{
            if(mountainArr.get(mid) < target)
                low=mid+1;
            else
                high = mid;
        }
    }
    return low;
}
int peak(MountainArray &mountainArr , int low, int high)
{
    while(low!=high)
    {
        int mid = low + (high-low)/2 ;
        if(mountainArr.get(mid) < mountainArr.get(mid+1))
            low = mid+1;
        else
            high = mid;
    }
    return low;
}
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        int peakidx = peak(mountainArr,1,n-2);
        int increasingidx = binarysearch(0,peakidx,target,mountainArr,true);
        if(mountainArr.get(increasingidx) == target)
            return increasingidx;
        int decreasingidx = binarysearch(peakidx+1,n-1,target,mountainArr,false);
        if(mountainArr.get(decreasingidx) == target)
            return decreasingidx;
        return -1;
    }
};