class Trie {
public:
	Trie(bool r) : IsRoot(r) {}
	~Trie() {
		for (auto* ptr:children) if (ptr) delete ptr;
	}
	bool IsWord = false;
	bool IsRoot;
	std::array<Trie*, 26> children = {nullptr};
	Trie* next(char c) {
		int id = c - 'a';
		auto nex = children[id];
		return nex;
	}
	void insert(string& s) {
		Trie* t=this;
		for(char c:s) {
			Trie* nex = t->next(c);
			if (!nex) {
				nex = new Trie(false);
				int id = c - 'a';
				t->children[id] = nex;
			}
			t = nex;
		}
		t->IsWord = true;
	}
};
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		Trie trie(true);
		for (auto& w: wordDict) {
			trie.insert(w);
		}
		vector<Trie*> pool(1, &trie);
		for (char c:s) {
			if (pool.empty()) return false;
			vector<Trie*> nextpool;
			bool hasNewStart = false;

			for(auto* t : pool) {
				Trie* nex = t->next(c);
				if (nex) {
					if (nex->IsWord && !hasNewStart) {
						hasNewStart = true;
						nextpool.push_back(&trie);
					}
					nextpool.push_back(nex);
				}
			}
			pool = nextpool;
		}
		for (auto* t:pool) if (t->IsRoot) return true;

		return false;
	}
};
