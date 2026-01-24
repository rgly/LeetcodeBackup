// Time : Beats 94.09%
// Memory : Beats 63.73%
class DetectSquares {
public:
	unordered_map<int, unordered_map<int, int> > plane;
	DetectSquares() {
	}

	void add(vector<int> point) {
		int x = point[0];
		int y = point[1];
		if (plane.count(x) == 0) {
			plane[x] = {{y, 1}};
		} else if (plane[x].count(y) == 0) {
			plane[x][y] = 1;
		} else {
			++plane[x][y];
		}
	}

	void count(vector<int> point) {
		int x = point[0];
		int y = point[1];
		if (plane.count(x) == 0) {
			return 0;
		} else {
			int num = 0;
			// check along Y axis
			for (auto it=plane[x].begin();
					it !=plane[x].end(); ++it) {
				int newy = it->first;
				if (newy == y) continue;
				int dis = newy - y;
				int point_num = it->second;

				// check along X axis
				array<int, 2> a = {x-dis, x+dis};
				for (auto newx : a) {
					if (plane.count(newx) != 0
						&& plane[newx].count(y)
						&& plane[newx].count(newy)) {
							num += plane[newx][y]
								* plane[newx][newy]
								* point_num;
					}
				}
			}
			return num;
		}
	}
};
