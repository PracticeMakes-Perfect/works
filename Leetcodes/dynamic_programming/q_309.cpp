/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

    After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

Example 2:

Input: prices = [1]
Output: 0

 

Constraints:

    1 <= prices.length <= 5000
    0 <= prices[i] <= 1000


*/

class Solution {
private:
    int iterative_02(vector<int>& prices) {
        std::vector<int> mp(prices.size() + 2);

        for (int i = prices.size() - 1; i > -1; --i) {
            //for case 1
            int c1 = 0;

            for (int sell = i + 1; sell < prices.size(); ++sell) {
                int profit = (prices[sell] - prices[i]) + mp[sell + 2];
                c1 = std::max(c1, profit);
            }

            //for case 2
            int c2 = mp[i + 1];

            //get max
            mp[i] = std::max(c1, c2);
        }

        return mp[0];
    }

    int iterative_best(vector<int>& prices) {
        int n = prices.size();
        if (n == 1) {
            return 0;
        }
        int rest = 0;
        int sold = 0;
        int hold = -prices[0];

        // the sequence here is important, if you do not use a temp variable to hold the state before changed
        for (int i = 1; i < n; ++i) {
            hold = std::max(hold, rest - prices[i]);
            rest = std::max(rest, sold);
            sold = std::max(sold, hold + prices[i]);
        }

        return sold;
        /*
        int sold = -1001;
        int held = -1001;
        int reset = 0;

        for (int p : prices) {
            int preSold = sold;

            sold = held + p;
            held = std::max(held, reset - p);
            reset = std::max(reset, preSold);
        }

        return std::max(sold, reset);
        */
    }

    int recursive(vector<int>& prices) {
        return -1;
    }


public:
    int maxProfit(vector<int>& prices) {
        //return recursive(prices);
        return iterative_best(prices);
        //return iterative_02(prices);
    }
};