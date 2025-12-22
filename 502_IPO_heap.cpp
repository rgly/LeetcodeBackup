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
		priority_queue<int> profit_window;
		for (int j=0; j<k; ++j) {
			for (;i<cappro.size();++i) {
				int caprequire = cappro[i].first;
				if (caprequire > cap) break;
				int pro = cappro[i].second;
				profit_window.push(pro);
			}
			if (profit_window.empty()) break;
			int maxpro = profit_window.top();
			profit_window.pop();
			cap += maxpro;
		}
		return cap;
	}
