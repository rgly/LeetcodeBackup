class Solution {
public:
	bool DFS(vector<vector<char>>& board, string& word,
			int i, int j, int state){
		const int m = board.size();
		const int n = board.front().size();
		char c = word[state];
		if (c != board[i][j]) return false;
		state += 1;

		if (state == word.size()) return true;
		// denote the explored path,
		// since only English is used, \0 is enough.
		board[i][j] = '\0';

		if (i>0)
			if(DFS(board,word,i-1, j, state)) return true;
		if (j>0)
			if(DFS(board,word,i, j-1, state)) return true;
		if (i<m-1)
			if(DFS(board,word,i+1, j, state)) return true;
		if (j<n-1)
			if(DFS(board,word,i, j+1, state)) return true;
		board[i][j] = c;
		return false;
	}

	bool exist(vector<vector<char>>& board, string word){
		const int m = board.size();
		if (m==0) return false;
		const int n = board.front().size();
		if (n==0) return false;

		// length pruning
		if (m*n < word.size()) return false;

		// character count pruning
		map<char, int> m1;
		for(int i=0;i<m;++i)
		for(int j=0;j<n;++j) {
			char c = board[i][j];
			if (m1.count(c) == 0) m1[c]=0;
			++m1[c];
		}
		map<char, int> m2;
		for (char c: word) {
			if (m2.count(c) == 0) m2[c]=0;
			++m2[c];
		}
		for (auto& p: m2) {
			const char c = p.first;
			const int wordcount = p.second;
			if (m1.count(c) ==0) return false;
			if (m1[c] < wordcount) return false;
		}

		// endpoint optimization
		if (m1[word.front()] > m1[word.back()]) {
			std::reverse(word.begin(), word.end());
		}

		for(int i=0;i<m;++i)
		for(int j=0;j<n;++j) {
			bool b = DFS(board, word, i, j, 0);
			if (b) return true;
		}
		return false;
	}
};
