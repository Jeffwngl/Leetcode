class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // three states
        // rest, sold, hold
        int n = prices.size();
        
        vector<int>rest(n);
        vector<int>sold(n);
        vector<int>hold(n);

        rest[0] = 0; // rest
        sold[0] = 0; // selling
        hold[0] = -prices[0]; // buying

        vector<vector<int>>dp(n, vector<int>(n, 0));

        for (size_t i = 1; i < n; ++i) {
            // keep holding from yesterday or buy new stock
            hold[i] = max(hold[i - 1], rest[i - 1] - prices[i]);
            // keep resting or rest because just sold
            rest[i] = max(rest[i - 1], sold[i - 1]);
            // can only sell if you were holding yesterday
            sold[i] = hold[i - 1] + prices[i];
        }

        return max(sold[n - 1], rest[n - 1]);
    }
};

// for [1,2,3,0,2]
// hold: -1, -1, -1, 1, 1, 
// rest: 0, 0, 1, 2, 2, 
// sold: 0, 1, 2, -1, 3, 

// rest[i] = maximum profit achievable at day i if we do not hold a stock and did not sell today, i.e. you were resting yesterday or you just sold yesterday
// hold[i] = Maximum profit at the end of day i if you are holding a stock, i.e., you were holding yesterday or you bought today
// sold[i] = Maximum profit at the end of day i if you sold a stock today. i.e. you just sold so you were holding yesterday
