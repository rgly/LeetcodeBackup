// Time : Beats 6.64%
// Memory : Beats 83.28%

class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		if (temperatures.empty()) return {};
		int n = temperatures.size();
		vector<int> ret(n, 0);
		stack<pair<int,int>> s;
		s.push({temperatures.back(), n-1});
		ret[n-1] = 0;
		for (int i = n-2; i>=0; --i) {
			int t = temperatures[i];
			while (!s.empty() && t >= s.top().first) {
				s.pop();
			}
			ret[i] = s.empty() ? 0 : s.top().second - i;
			s.push({t, i});
		}
		return ret;
	}
};
