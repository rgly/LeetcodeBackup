class Solution {
public:
	// use 2D array to record profit
	// dimension 1: days
	// dimension 2: state
	//				0: 1st buy, profit = -price
	//				1: 1st sell
	//				2: 2nd buy
	//				3: 2nd sell
	int maxProfit(vector<int>& prices) {
		const int n = prices.size();
		if (n<=1) return 0;
		if (n==2) return max(0, prices[1]-prices[0]);

		// only record last day's state and profit
		array<int, 4> profit;
		profit[0] = -prices[0];
		std::fill(profit.begin()+1, profit.end(), INT_MIN);
		for (int i=1; i<n; ++i) {
			int p = prices[i];
			// 2ndsell -> 
			// 2ndbuy -> 2ndsell
			profit[3] = max(profit[3], profit[2]+p);

			// 2ndbuy ->
			// 1ndsell -> 2ndbuy
			if (profit[1] > INT_MIN+p)
			profit[2] = max(profit[2], profit[1]-p);

			// 1ndsell -> 
			// 1ndbuy -> 1ndsell
			profit[1] = max(profit[1], profit[0]+p);

			// 1ndbuy ->
			// idle   -> 1ndbuy
			profit[0] = max(profit[0], -p);
		}
		int pro = max(profit[1], profit[3]);
		pro = max(pro, 0); // if don't buy stock
		return pro;
	}
};
