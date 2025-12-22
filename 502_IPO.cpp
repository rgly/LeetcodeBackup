class Solution {
public:
	// k: projects
	// w: initial capital
	int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
		// sort the captial-profit list
		vector<pair<int,int>> cappro;
		for(int i=0;i<profits.size();++i) {
			cappro.push_back({capital[i] , profits[i] });
		}
		sort(cappro.begin(), cappro.end());

		// use Kth largest heap to sweep under capital limit.
		int i=0;
		int cap=w;
		multiset<int> profit_window;
		int threshold = 0;
		for (int j=0; j<k; ++j) {
			for (;i<cappro.size();++i) {
				int caprequire = cappro[i].first;
				if (caprequire > cap) break;
				int pro = cappro[i].second;
				if (profit_window.size() < k) {
					profit_window.insert(pro);
					threshold = *profit_window.begin();
				} else if (pro > threshold) {
					profit_window.insert(pro);
					profit_window.erase(profit_window.begin());
					threshold = *profit_window.begin();
				}
			}
			if (profit_window.empty()) break;
			int maxpro = *profit_window.rbegin();
			cap += maxpro;
			profit_window.erase(profit_window.find(maxpro));
		}
		return cap;
	}
