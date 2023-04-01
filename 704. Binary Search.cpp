class Solution {
public:
    int search(vector<int>& a, int target) {
        int s=0,e=a.size()-1;
        while(s <= e){
            int mid = (s + e) >> 1;
            if(a[mid] == target ) return mid;
            else if(a[mid] > target) e = mid - 1;
            else s = mid + 1;
        }
        return -1;
    }
};