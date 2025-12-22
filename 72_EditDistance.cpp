class Solution {
public:
	int minDistance(string word1, string word2) {
		// use 2D array to record modify distance
		// where i is used word1 character count,
		// and j is used word2 character count,
		// Distance[i][j] = min(
		//		Distance[i-1][j] +1, // remove word1[i-1]
		//		Distance[i][j-1] +1, // add word2[j-1]
		//		Distance[i-1][j-1] + int(word1[i-1]!=word2[j-1]) // check if need replace
		//  )

		// length check
		const int m = word1.size();
		const int n = word2.size();
		if (m==0) return n;
		if (n==0) return m;
		if (word1 == word2) return 0;

		vector<int> Distance(n+1);
		// i=0
		iota(Distance.begin(), Distance.end(), 0);
		for(int i=1; i<=m; ++i) {
			int topleft = Distance[0];
			Distance[0] = i;
			for(int j=1; j<=n; ++j) {
				int top = Distance[j];
				int left = Distance[j-1];
				Distance[j] = min(left, top)+1;
				if (word1[i-1] != word2[j-1]) topleft +=1;
				Distance[j] = min(topleft, Distance[j]);
				topleft = top;
			}
		}
		return Distance[n];
	}
};
