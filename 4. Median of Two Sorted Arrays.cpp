Complexity
Time complexity: O(m+n)O(m+n)O(m+n)
Space complexity: O(m+n)O(m+n)O(m+n)


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int i=0,j=0;
        
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]) merged.push_back(nums1[i++]);
            else merged.push_back(nums2[j++]);
        }

        while(i<nums1.size()) merged.push_back(nums1[i++]);

        while(j<nums2.size()) merged.push_back(nums2[j++]);

        double median;
        int n = merged.size();

        if(n%2 == 1) median  = merged[n/2];
        else median = (merged[(n-1)/2] + merged[n/2]) / 2.0;

        return median;
    }
};