class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        //at each day i we can either buy or sell 
        //dp(i)(0) ending by buying stock at i-th day
        //dp(i)(1) ending by selling stock
        if(n == 0) return 0;
        dp[0][0] = -prices[0];
        for(int day = 1; day < (int)prices.size(); day++){
            dp[day][0] = max(dp[day-1][0],-prices[day]);
            if(day-2>=0) dp[day][0] = max({dp[day][0], dp[day-2][1]-prices[day], -prices[day]});
            dp[day][1] = max(dp[day-1][1], dp[day-1][0]+prices[day]);
        }
        return max(dp[n-1][1],dp[n-1][0]);
    }
};
