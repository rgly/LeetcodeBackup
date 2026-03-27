// Time : Beats 100%
// Memory : Beats 84.27%
class Solution {
public:
	// One day cooldown after selling stocks.
	// DP[i][0] = max(DP[i-1][0], DP[i-1][1]+prices[i])
	// DP[i][1] = max(DP[i-2][0]-prices[i], DP[i-1][1])
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n==1) return 0;
		vector<vector<int>> DP(2, vector<int>(2));
		DP[0][0] = 0;
		DP[0][1] = -prices[0];
		DP[1][0] = max(prices[1] - prices[0], 0);
		DP[1][1] = -min(prices[1], prices[0]);
		for (int i=2; i<n; ++i) {
			int DP0 = max(DP[1][0], DP[1][1]+prices[i]);
			int DP1 = max(DP[0][0]-prices[i], DP[1][1]);
			// shift
			DP[0][0] = DP[1][0];
			DP[0][1] = DP[1][1];
			DP[1][0] = DP0;
			DP[1][1] = DP1;
		}
		return DP[1][0];
	}
};
