// Time : Beats 5.00%
// Memory : Beats 20.96%
// TODO: 	1. limit memory use for only recent max(coins) amouts
//			2. pre-sum the CoinID dimension for first-k coins use
class Solution {
public:
	int changeImpl(int amount, vector<int>& coins, int CoinID, vector<vector<int>>& v) {
		if (v[amount][CoinID] != -1) return v[amount][CoinID];
		const int n = coins.size();
		// coins loop
		int c = coins[CoinID];
		v[amount][CoinID] = 0;
		if (amount-c < 0) return 0;
		// sum of possible coins loop
		for (int k=0; k<=CoinID; ++k) {
			v[amount][CoinID] += changeImpl(amount-c, coins, k, v);
		}
		return v[amount][CoinID];
	}
	// A Top-down DP, but need to record if using first i type coins
	int change(int amount, vector<int>& coins) {
		const int n = coins.size();
		sort(coins.begin(), coins.end());
		vector<vector<int>> v(amount+1, vector<int>(n, -1));
		fill(v[0].begin(), v[0].end(), 0);
		// let v[coin][coin] = 1 using this base.
		v[0][0] = 1;
		int ret=0;
		for (int k=0; k<n; ++k) {
			ret += changeImpl(amount, coins, k, v);
		}
		// amount loop
		return ret;
	}
};
