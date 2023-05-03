class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1;
        unordered_set<int> set2;
        for(int i=0; i<nums1.size(); i++)
        {
            set1.insert(nums1[i]);
        }
        for(int i=0; i<nums2.size(); i++)
        {
           set2.insert(nums2[i]);
        }
        vector<int> a,b;
        for(int i=0; i<nums1.size(); i++)
        {
            if(set2.find(nums1[i])==set2.end())
            {   
                a.push_back(nums1[i]);
                set2.insert(nums1[i]);
            }

        }
        for(int i=0; i<nums2.size(); i++)
        {
            if(set1.find(nums2[i])==set1.end())
            {
                b.push_back(nums2[i]);
                set1.insert(nums2[i]);
            }
        }
        return {a,b};
    }
};