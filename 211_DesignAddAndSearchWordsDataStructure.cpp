// Design a data structure that supports adding new words and finding if a string matches any previously added string.
// at most 2 dot for search
// only lower english letters and dot
class Trie {
private:
	std::array<Trie*,26> sub={nullptr};
	bool IsEndOfWord = false;

public:
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

	bool search(string s) {
		Trie* cur = this;
		for (int k=0;k<s.size();++k) {
			char c=s[k];
			if (c=='.') {
				string s1 = s.substr(k+1);
				for (int j=0;j<26;++j) {
					auto* subcur = cur->sub[j];
					if (subcur) {
						if (subcur->search(s1)) return true;
					}
				}
				return false;
			}
			int i = c-'a';
			if (!cur->sub[i]) return false;
			cur = cur->sub[i];
		}
		return cur->IsEndOfWord;
	}
};

class WordDictionary {
public:
	Trie trie;
	WordDictionary() {}
	void addWord(string word) {trie.insert(word);}
	bool search(string word) {return trie.search(word);}
};
