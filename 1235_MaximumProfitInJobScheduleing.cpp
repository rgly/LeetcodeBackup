// Time : Beats 74.11%
// Memory : Beats 79.69%
class Solution {
public:
	int jobScheduleing(vector<int>& startTime, 
						vector<int>& endTime, 
						vector<int>& profit) {
		int n = startTime.size();
		if (n == 0) return 0;
		assert(endTime.size() == n);
		assert(profit.size() == n);
		typedef tuple<int, int, int> JobTy;
		typedef pair<int, int> JobTy2;
		vector<JobTy> jobs;
		for (int i=0; i<n; ++i) {
			jobs.push_back({startTime[i], endTime[i], profit[i]});
		}
		sort(jobs.begin(), jobs.end());
		priority_queue<JobTy2, vector<JobTy2>, greater<JobTy2> > minheap;
		int cur_pro = 0;
		for (auto t: jobs) {
			auto [start, end, pro] = t;
			while (!minheap.empty()
					&& minheap.top().first <= start) {
				cur_pro = max(cur_pro, minheap.top().second);
				minheap.pop();
			}
			minheap.push({end, cur_pro+pro});
		}
		while (!minheap.empty()) {
			cur_pro = max(cur_pro, minheap.top().second);
			minheap.pop();
		}
		return cur_pro;
	}
}; 
