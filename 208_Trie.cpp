class Trie {
public:
	std::array<Trie*,26> sub={nullptr};
	bool IsEndOfWord = false;

	Trie(){}
	~Trie(){ for (auto t:sub) if (t) delete t;}

	void insert(string s) {
		Trie* cur = this;
		for (char c:s) {
			int i = c-'a';
			if (!cur->sub[i]) cur->sub[i]= new Trie();
			cur = cur->sub[i];
		}
		cur->IsEndOfWord = true;
	}

	bool startsWith(string s) {
		Trie* cur = this;
		for (char c:s) {
			int i = c-'a';
			if (!cur->sub[i]) return false;
			cur = cur->sub[i];
		}
		return true;
	}

	bool search(string s) {
		if (s.empty()) return true;
		Trie* cur = this;
		for (char c:s) {
			int i = c-'a';
			if (!cur->sub[i]) return false;
			cur = cur->sub[i];
		}
		return cur->IsEndOfWord;
	}
};
