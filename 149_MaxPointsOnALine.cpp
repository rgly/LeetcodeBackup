class Solution {
public:
	typedef pair<int,int> Ty;
	int gcd(int a, int b) {
		if (a==1 || b==1 || a==0 || b==0) return 1;
		while (a != 0 && b!= 0) {
			if (a<b) b = b % a;
			else a = a % b;
		}
		if (a == 0) return b;
		else return a;
	}
	int maxPoints(vector<vector<int>>& points) {
		int size = points.size();
		if (size <= 1) return size;
		else if (size == 2) return 2;

		int maxpoints = 0;
		for (int i=0; i<size;++i) {
			map<Ty, int> m;
			bool update = false;
			for (int j=i+1; j<size;++j) {
				int x1 = points[i][0];
				int y1 = points[i][1];
				int x2 = points[j][0];
				int y2 = points[j][1];

				// every line becomes y = ax+b = (a1/a2)x+b
				int a1 = y2-y1;
				int a2 = x2-x1;
				if (a2 < 0) {a2 = -a2; a1 = -a1;}
				// vertical line
				if (a1!=0 && a2==0) a1 =1;
				// horizontal line
				else if (a1==0 && a2!=0) a2 =1;
				int g = (a1 < 0) ? gcd(-a1, a2): gcd(a1, a2);
				a1 = a1/g;
				a2 = a2/g;
				Ty t = {a1,a2};
				if (m.count(t) == 0) m[t] = 2;
				else ++m[t];

				if (m[t] > maxpoints) maxpoints = m[t];
			}
			// overlap points
			if (m.count({0,0}) !=0 && update) maxpoints += m[{0,0}]-1;
		}
		return maxpoints;
	}
};
