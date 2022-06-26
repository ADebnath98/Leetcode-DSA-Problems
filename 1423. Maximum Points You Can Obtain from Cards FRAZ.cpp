class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int c = 0, i = 0, j, sum = 0, n = cardPoints.size(), ans = 0;
        for(j = 0; c< n-k; j++, c++)
        {
            sum += cardPoints[j];
        }
        
        int total_sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        ans = max(ans, total_sum - sum);
        while(j < cardPoints.size())
        {
            sum -= cardPoints[i++];
            sum += cardPoints[j++];
            ans = max(ans, total_sum - sum);
        }
        return ans;
    }
};