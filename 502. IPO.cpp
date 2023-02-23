using pii = pair<int, int>;

class Solution {
public:
    int findMaximizedCapital(
        const int mx_proj, int curr_cap, 
        const vector<int>& profits, const vector<int>& capital
    ) {
        priority_queue<pii, vector<pii>, greater<pii>> cap_minq;
        priority_queue<int> profit_maxq;

        for (int i = 0; i < profits.size(); i++) {
            if (capital[i] <= curr_cap) profit_maxq.push(profits[i]);
            else cap_minq.push({capital[i], profits[i]});
        }

        for (int i = 0; i < mx_proj; i++) {
            if (profit_maxq.empty()) break;
            curr_cap += profit_maxq.top();
            profit_maxq.pop();

            while (!cap_minq.empty() && cap_minq.top().first <= curr_cap) 
                profit_maxq.push(cap_minq.top().second), cap_minq.pop();
        }

        return curr_cap;
    }
};