class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue <int, vector<int>, greater<int> > headWorkers;
        priority_queue <int, vector<int>, greater<int> > tailWorkers;

        for(int i = 0; i < candidates; i++){
            headWorkers.push(costs[i]);
        }
        int idx = (candidates > costs.size()-candidates) ? candidates : costs.size()-candidates;
        for(int i = idx ; i < costs.size(); i++){
            tailWorkers.push(costs[i]);
        }

        int nextHead = candidates;
        int nextTail = costs.size() - 1 - candidates;
        long long ans = 0;

        for(int i = 0; i < k; i++){
            if(tailWorkers.empty() || !headWorkers.empty() && headWorkers.top() <= tailWorkers.top()){
                ans += headWorkers.top();
                headWorkers.pop();

                if(nextHead <= nextTail){
                    headWorkers.push(costs[nextHead]);
                    nextHead++;
                }
            }
            else{
                ans += tailWorkers.top();
                tailWorkers.pop();

                if(nextHead <= nextTail){
                    tailWorkers.push(costs[nextTail]);
                    nextTail--;
                }
            }
        }
        return ans;
    }
};