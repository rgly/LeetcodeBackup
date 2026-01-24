// Time : Beats 100%
// Memory : Beats 89.10%
class Solution {
public:
	// DP
	int minCostClimbingStairs(vector<int>& cost) {
		int n = cost.size();
		int cur = 0;
		int last = 0;
		for (int i=0; i<n-1; ++i) {
			int next = min(cur+cost[i+1], last+cost[i]);
			last = cur;
			cur = next;
		}
		return cur;
	}
};
