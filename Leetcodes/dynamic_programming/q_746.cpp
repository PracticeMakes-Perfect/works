/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.

 

Constraints:

    2 <= cost.length <= 1000
    0 <= cost[i] <= 999


*/

class Solution {
private:
    int iterative(std::vector<int>& cost) {
        /*
        int n = cost.size();
        std::vector<int> minCost(n + 1, 0);

        for (int i = 2; i < n + 1; ++i) {
            minCost[i] = std::min(cost[i - 1] + minCost[i - 1], cost[i - 2] + minCost[i - 2]);
        }

        return minCost[n];
        */
        
        int n = cost.size();

        if (n == 2) {
            return std::min(cost[0], cost[1]);
        }

        std::vector<int> dp(n, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < n; ++i) {
            dp[i] =  cost[i] + std::min(dp[i - 1], dp[i - 2]);
        }

        return std::min(dp[n - 1], dp[n - 2]);
    }

    int recursive(std::vector<int>& cost, int n, std::vector<int>& mem) {
        if (n < 0) {
            return 0;
        }

        if (n == 0) {
            mem[0];
        }

        if (n < cost.size() && mem[n] != -1) {
            return mem[n];
        }

        int cost_m1 = recursive(cost, n - 1, mem);
        int cost_m2 = recursive(cost, n - 2, mem);

        if (n < cost.size()) {
            mem[n] = cost[n] + std::min(cost_m1, cost_m2);
        } else {
            mem[n] = std::min(cost_m1, cost_m2);
        }
        
        return mem[n];
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        /*
        int n = cost.size();
        std::vector<int> mem(n + 1, -1);
        mem[n] = 0;
        mem[0] = cost[0];

        return recursive(cost, n, mem);
        */

        return iterative(cost);
    }
};