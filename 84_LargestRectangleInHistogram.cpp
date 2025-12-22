class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		// height, index
		// an increaing bar
		stack<pair<int, int>> st;
		int maxarea=0;
		for (int i=0; i<heights.size(); ++i) {
			int h = heights[i];
			int hbegin = i;
			while (!st.empty() && st.top().first > h) {
				int h1 = st.top().first;
				int w1 = i - st.top().second;
				maxarea = max(h1*w1, maxarea);
				hbegin = min(hbegin, st.top().second);
				st.pop();
			}
			if (st.empty() || st.top().first < h) {
				st.push({h, hbegin});
			}
		}
		while (!st.empty()) {
			int h1 = st.top().first;
			int w1 = heights.size() - st.top().second;
			maxarea = max(h1*w1, maxarea);
			st.pop();
		}
		return maxarea;
	}
};
