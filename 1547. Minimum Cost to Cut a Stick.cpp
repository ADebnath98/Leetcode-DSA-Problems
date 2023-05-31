class Solution
{
public:
    int minCost(const int n, std::vector<int> &cuts)
    {
        cuts.push_back(0);
        std::sort(cuts.begin(), cuts.end());
        cuts.push_back(n);
        const int m = cuts.size();
        std::optional<std::pair<int, int>> dp[m][m];

        for (int i = m - 1; i-- != 0;)
        {
            dp[i][i + 1] = {0, i};
            for (int j = i + 1; ++j != m;)
            {
                std::optional<std::pair<int, int>> x;
                const int cost = cuts[j] - cuts[i];
                const int max_k = std::min(dp[i + 1][j]->second, j - 1);
                for (int k = std::max(i + 1, dp[i][j - 1]->second); k <= max_k; ++k)
                {
                    const int new_cost = dp[i][k]->first + dp[k][j]->first + cost;
                    if (!x.has_value() || new_cost < x->first)
                    {
                        x = {new_cost, k};
                    }
                }
                dp[i][j] = x;
            }
        }
        return dp[0][m - 1]->first;
    }
};