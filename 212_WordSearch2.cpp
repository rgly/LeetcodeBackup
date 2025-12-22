class Trie {
private:
	std::array<Trie*,26> sub={nullptr};
	Trie* source = nullptr;
	int BranchNum = 0;

public:
	string ID;

	Trie() {}
	~Trie(){ for (auto t:sub) if (t) delete t;}

	Trie* next(char c) {
		if (this->BranchNum == 0) return nullptr;
		int i = c-'a';
		return this->sub[i];
	}

	void insert(string s) {
		Trie* cur = this;
		for (char c:s) {
			int i = c-'a';
			if (!cur->sub[i]) {
				auto* t = new Trie();
				t->source = cur;
				cur->sub[i] = t;
				++(cur->BranchNum);
			}
			cur = cur->sub[i];
		}
		cur->ID = s;
	}

	void clean(){
		this->ID = "";
		auto* cur = this;
		while (cur->BranchNum == 0) {
			cur = cur->source;
			if (!cur) break;
			assert(cur->BranchNum);
			--(cur->BranchNum);
			if (!cur->ID.empty()) break;
		}
	}

	bool IsWord() { return ! this->ID.empty(); }
};

class Solution {
private:
	vector<vector<bool>> path;

public:

vector<string> DFS(Trie* trie, vector<vector<char>>& board, int i, int j){
	const int m = board.size();
	const int n = board.front().size();

	if (trie == nullptr) return {};
	char c = board[i][j];
	auto t = trie->next(c);
	if (t == nullptr) return {};

	path[i][j] = true;

	vector<string> ret;
	if (i>0 && !path[i-1][j]) {
		auto v = DFS(t, board, i-1, j);
		ret.insert(ret.end(), v.begin(), v.end());
	}
	if (j>0 && !path[i][j-1]) {
		auto v = DFS(t, board, i, j-1);
		ret.insert(ret.end(), v.begin(), v.end());
	}
	if (i<m-1 && !path[i+1][j]) {
		auto v = DFS(t, board, i+1, j);
		ret.insert(ret.end(), v.begin(), v.end());
	}
	if (j<n-1 && !path[i][j+1]) {
		auto v = DFS(t, board, i, j+1);
		ret.insert(ret.end(), v.begin(), v.end());
	}

	if (t->IsWord()) {
		ret.push_back(t->ID);
		t->clean();
	}
	path[i][j] = false;
	return ret;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
	const int m = board.size();
	if (m==0) return {};
	const int n = board.front().size();
	path.resize(m, vector<bool>(n, false));

	Trie trie;
	for (int i=0; i<words.size();++i) trie.insert(words[i]);

	vector<string> ret;
	for (int i=0;i<m;++i)
	for (int j=0;j<n;++j) {
		auto v = DFS(&trie, board, i, j);
		ret.insert(ret.end(), v.begin(), v.end());
	}
	return ret;
}
};
