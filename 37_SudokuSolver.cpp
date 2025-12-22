class Solution {
public:
	typedef array<array<bool, 9>, 9> VioTy;
	VioTy rows;
	VioTy cols;
	VioTy blks;
	int getBlk(int i, int j) {
		int b = j/3;
		return i-(i%3)+b;
	}

	bool backtrace(vector<vector<char>>& board, int i, int j) {
		if (i==9 && j==0) return true;
		char c = board[i][j];
		if (c != '.') {
			return backtrace(board, i+(j/8), (j+1)%9);
		}

		// try 1-9
		for (int val=0; val<9; ++val) {
			bool vio = rows[i][val] | cols[j][val] | blks[getBlk(i,j)][val];
			if (vio) continue;

			rows[i][val] = true;
			cols[j][val] = true;
			blks[getBlk(i,j)][val] = true;
			bool ret = backtrace(board, i+(j/8), (j+1)%9);
			if (ret) {
				board[i][j] = '1' + val;
				return true;
			}

			rows[i][val] = false;
			cols[j][val] = false;
			blks[getBlk(i,j)][val] = false;
		}
		return false;
	}
	void soluveSudoku(vector<vector<char>>& board) {
		for (int i=0; i<9; ++i)
		for (int j=0; j<9; ++j) {
			rows[i][j] = false;
			cols[i][j] = false;
			blks[i][j] = false;
		}

		for (int i=0; i<9; ++i)
		for (int j=0; j<9; ++j) {
			char c = board[i][j];
			if (c == '.') continue;
			int val = c - '1';
			rows[i][val] = true;
			cols[j][val] = true;
			blks[getBlk(i,j)][val] = true;
		}
		bool cond = backtrace(board, 0, 0);
		assert(cond);
	}
};
