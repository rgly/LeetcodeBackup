//Time : Beats 100%
//Memory : Beats 86.78%
class Solution {
public:
	void dfs(vector<vector<int>>& image,
						int sr, int sc,
						int origincolor, int color) {
		int c = image[sr][sc];
		if (c != origincolor) return;
		image[sr][sc] = color;
		if (sr >0) dfs(image, sr-1, sc, c, color);
		if (sc >0) dfs(image, sr, sc-1, c, color);
		if (sr < image.size()-1) dfs(image, sr+1, sc, c, color);
		if (sc < image[0].size()-1) dfs(image, sr, sc+1, c, color);
	}
	vector<vector<int>> floodFill(vector<vector<int>>& image,
						int sr, int sc, int color) {
		int c = image[sr][sc];
		if (c!=color) dfs(image, sr, sc, c, color);
		return image;
	}
};
