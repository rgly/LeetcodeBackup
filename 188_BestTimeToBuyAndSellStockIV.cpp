class Solution {
public:
	// use 2D array to record profit
	// dimension 1: days
	// dimension 2: state
	//				0: 1st buy, profit = -price
	//				1: 1st sell
	//				2: 2nd buy
	//				3: 2nd sell
	//				4: 3nd buy
	//				5: 3nd sell
	//				6: ...
	int maxProfit(int k, vector<int>& prices) {
		const int n = prices.size();
		if (k==0) return 0;
		if (n<=1) return 0;
		if (n==2) return max(0, prices[1]-prices[0]);

		// only record last day's state and profit
		vector<int> profit(2*k, INT_MIN);
		profit[0] = -prices[0];
		for (int i=1; i<n; ++i) {
			int p = prices[i];
			for (int j=k-1;j>=1;--j) {
				int z = 2*j;
				// jthsell -> 
				// jthbuy -> jthsell
				profit[z+1] = max(profit[z+1], profit[z]+p);

				// jthbuy ->
				// (j-1)thsell -> jthbuy
				if (profit[z-1] >= INT_MIN+p)
				profit[z] = max(profit[z], profit[z-1]-p);
			}

			// 1ndsell -> 
			// 1ndbuy -> 1ndsell
			profit[1] = max(profit[1], profit[0]+p);

			// 1ndbuy ->
			// idle   -> 1ndbuy
			profit[0] = max(profit[0], -p);
		}
		int pro = 0; // if don't buy stock
		for (int i=0; i<k;++i) {
			pro = max(pro, profit[2*i+1]);
		}
		return pro;
	}
};
