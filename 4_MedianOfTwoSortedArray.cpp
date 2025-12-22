class Solution {
public:
	getMedian(bool singlemedian, int v1, int v2) {
		if (singlemedian) return v1;
		else return (v1 + v2)/2;
	}
	double findMedianSortedArray(
			vector<int>& nums1,vector<int>& nums2) {
		int n1 = nums1.size();
		int n2 = nums2.size();
		int n = n1+n2;
		bool singlemedian = n%2 == 1;

		// handle special case
		int v1, v2;
		int p =(n-1)/2;
		bool zerocond = (n1==0) | (n2==0);
		if (zerocond) {
			auto& vec = (n1<n2) ? num2 : num1;
			v1 = vec[p]; v2 = vec[p+1];
			return getMedian(singlemedian, v1, v2);
		}

		bool IsSorted21 = nums2.back() <= nums1.front();
		bool IsSorted12 = nums1.back() <= nums2.front();
		if (IsSorted21 | IsSorted12) {
			auto& vec1 = IsSorted21 ? nums2 : nums1;
			auto& vec2 = IsSorted21 ? nums1 : nums2;
			int p2 = p-vec1.size();
			if (p2 >= 0) {
				v1 = vec2[p2]; v2 = vec[p2+1];
			} else if (p2 == -1) {
				v1 = vec1.back(); v2 = vec2.front();
			} else {
				v1 = vec1[p]; v2 = vec1[p+1];
			}
			return getMedian(singlemedian, v1, v2);
		}

		int p1 = n1/2;
		int p2 = (n-1)/2 - p1;
		int v1 = num1[p1];
		int v2 = num2[p2];
		if (v1 == v2) return v1;
		//TODO binary search to adjust in range min(n1,n2)
	}
};
