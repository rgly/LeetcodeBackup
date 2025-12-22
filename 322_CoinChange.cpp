class Solution {
public:
	int gcd(int a, int b) {
		if (a==0 || b==0 || a==1 || b==1) return 1;
		while (a!=0 && b!=0) {
			if (a<b) b = b%a;
			else a = a%b;
		}
		if (a!=0) return a;
		else return b;
	}
	int gcd(vector<int>& v) {
		assert(v.size() >=1);
		int g = v[0];
		for (int i = 1;i<v.size();++i) {
			g = gcd(g,v[i]);
			if (g==1 || g==0) return g;
		}
		return g;
	}
	int lcm(vector<int>& v) {
		assert(v.size() >=1);
		if (v.size()==1) return v.front();
		// use float to check overflow
		float multiple = 1; 
		for (int val: v) multiple *= val;
		if (2*multiple > INT_MAX) {
			return -1;
		} else {
			int LeastCommonMultiple = 1
			for (int val: v) LeastCommonMultiple *= val;
			int LeastCommonMultiple /= gcd(v);
			return LeastCommonMultiple;
		}
	}

	// return true if contains amount
	bool removeCoin(vector<int>& coins, int amount) {
		auto it = std::lower_bound(coins.begin(), coins.end(), amount);
		if (it!=coins.end() && *it == amount) return true;

		coins.erase(it, coins.end());
		return false;
	}
	int coinChange(vector<int>& coins, int amount) {
		if (amount == 0) return 0;
		if (coins.size() == 1) {
			if (amount%coins[0] == 0) return amount/coins[0];
			else return -1;
		}
		sort(coins.begin(), coins.end());

		// remove coin which larger than amount
		// also, if coin == amount returns
		bool has = removeCoin(coins, amount);
		if (has) return 1;
		if (coins.empty()) return -1;
		if (coins[0] < 0) return -1;

		// optimization: amount - least common multiple of coins
		int LeastCommonMultiple = lcm(coins);
		int LargestCoinCount = 0;
		if (LeastCommonMultiple != -1) {
			int LargestCoin = coins.back();
			LargestCoinCount = (amount/LeastCommonMultiple) * (LeastCommonMultiple/LargestCoin);
			amount = amount % LeastCommonMultiple;
		}
		if (amount == 0) return LargestCoinCount;

		// remove coin again which larger than amount
		// also, if coin == amount returns
		has = removeCoin(coins, amount);
		if (has) return LargestCoinCount+1;
		if (coins.empty()) return -1;

		// init
		vector<int> mincoin(amount+1, INT_MAX);
		mincoin[0] = 0;
		
		// 1+min(coinChange(coins, amount-coin[i]))
		for (int i=1;i<=amount;++i) {
			int cur_coins = INT_MAX;
			for (auto c:coins) {
				if (c>=amount) break;
				int left_amount = i-c;
				if (left_amount < 0) break;
				cur_coins = min(cur_coins, mincoin[left_amount]);
			}
			if (cur_coins != INT_MAX)
				mincoin[i] = cur_coins+1;
		}
		if (mincoin[amount] == INT_MAX) return -1;
		return mincoin[amount]+LargestCoinCount;
	}
};
