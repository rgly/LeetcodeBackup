class Solution {
public:
typedef tuple<int, int, int> Ty;
	void pushheap(
		priority_queue<Ty, vector<Ty>, greater<Ty>>& minheap,
				vector<int>& nums1, vector<int>& nums2,
				int i, int j){
		int sum = nums1[i] + nums2[j];
		minheap.push({sum, i, j});
	}
	int findKValue(vector<int>& num1, vector<int>& num2, int k){
		const int n1 = nums1.size();
		const int n2 = nums2.size();
		priority_queue<int> maxheap;
		pushheap(minheap, nums1, nums2, n1-1, n2-1);
		int thres;
		while(ret.size() < k) {
			auto [sum, i, j] = maxheap.top();
			minheap.pop();
			ret.push_back({nums1[i], nums2[j]});
			thres = sum;
			if (i<j || i==n1-1) {
				if (j-1 > 0) {
				pushheap(minheap, nums1, nums2, i, j-1);
				}
			}
			if (i-1>j || j==n2-1) {
				if (i-1 >0) {
				pushheap(minheap, nums1, nums2, i-1, j);
				}
			}
		}
		return thres;
	}

	vector<vector<int>> kSmallestPairs(
				vector<int>& nums1, vector<int>& nums2, int k){
		const int n1 = nums1.size();
		const int n2 = nums2.size();
		if (nums1.empty() || nums2.empty() ) return{};
		if (n1<k && n2<k && n1*n2<k) return{};
		vector<vector<int>> ret;
		// K covers all
		if (n1==k/n2 && n1*n2==k) {
			for (auto v1:nums1)
			for (auto v2:nums2)
			ret.push_back({v1, v2});
			return ret;
		}
		// if K covers beyond half, find the largest N-K+1
		// then use that sum of two values as threshold
		if (n1<2*k && n2<2*k && n1*n2<2*k) {
			int thres = findKValue(num1, num2, n1*n2-k+1);
			for (auto v1:nums1)
			for (auto v2:nums2)
			if (v1+v2 <= thres) ret.push_back({v1, v2});
			return ret;
		}
		// Use K-length min heap
		priority_queue<Ty, vector<Ty>, greater<Ty>> minheap;
		pushheap(minheap, nums1, nums2, 0, 0);
		while(ret.size() < k) {
			auto [sum, i, j] = minheap.top();
			minheap.pop();
			ret.push_back({nums1[i], nums2[j]});
			if (i>j || i==0) {
				if (j+1 < nums2.size()) {
				pushheap(minheap, nums1, nums2, i, j+1);
				}
			}
			if (i+1<j || j==0) {
				if (i+1 < nums1.size()) {
				pushheap(minheap, nums1, nums2, i+1, j);
				}
			}
		}
		return ret;
	}
};
