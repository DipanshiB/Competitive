class Solution {
public:
    int helper(int index, int numA, int numB, vector<vector<int>>& costs) {
        int n = costs.size();
        if(index == n) {
            return 0;
        }
        int costA = 0, costB = 0;
        //choose A 
        if(numA < n/2) {
            costA = costs[index][0] + helper(index+1, numA+1, numB, costs);
        }
        else costA = INT_MAX;
        //choose B
        if(numB < n/2) {
            costB = costs[index][1] + helper(index+1, numA, numB+1, costs);
        }
        else costB = INT_MAX;
        return min(costA, costB);
    }
    
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
         //return helper(0, 0, 0, costs);
        vector<pair<int, int>> costDiff;
        int n = costs.size();
        int numA = 0, numB = 0;
        int cost = 0;
        for(int i=0; i<costs.size(); i++) {
            costDiff.push_back({i, abs(costs[i][0] - costs[i][1])});
        }
        sort(costDiff.begin(), costDiff.end(), cmp);
        for(int i=0; i < n; i++) {
            if(costs[costDiff[i].first][0] < costs[costDiff[i].first][1]) {
                if(numA < n/2) {
                    numA++;
                    cost += costs[costDiff[i].first][0];
                }
                else {
                    numB++;
                    cost += costs[costDiff[i].first][1];
                }
            }
            else {
                if(numB < n/2) {
                    numB++;
                    cost += costs[costDiff[i].first][1];
                }
                else {
                    numA++;
                    cost += costs[costDiff[i].first][0];
                }
            }
        }
        return cost;
    }
};