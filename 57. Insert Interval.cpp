class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> result;

        int start=0, end=n-1;
        while(start<=end) {
            int mid = start+ (end-start)/2;
            if(intervals[mid][0] >= newInterval[0])
            end=mid-1;
            else
            start=mid+1;
        }
        intervals.insert(intervals.begin()+start, newInterval);
        result.push_back(intervals[0]);
        int resultIndex=0;
        for(int i=1;i<intervals.size();i++) {
            if(intervals[i][0] <= result[resultIndex][1]) {
                result[resultIndex][1] = max(intervals[i][1], result[resultIndex][1]);
            } else {
                result.push_back(intervals[i]);
                resultIndex++;
            }
        }
        return result;
    }
};