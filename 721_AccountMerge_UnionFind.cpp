// disjoint set union
class UnionFind {
public:
	vector<int> parent;
	vector<int> size;
	map<string, int> m;
	vector<string> reversem;
	void add(string s, int p) {
		if (m.count(s)) {
			// p == -1, do noting
			if (p == -1) return;
			// if already have parent, union p and find(s)
			int i = m[s];
			union(i, p);
		} else {
			int i = parent.size();
			m[s] = i;
			int par = (p!=-1)? p:i;
			parent.push_back(par);
			assert(size.size() == i);
			size.push_back(1);
			assert(reversem.size() == i);
			reversem.push_back(s);
		}
	}
	int find(int i) {
		if (parent[i] == i) return i;
		else {
			auto root = find(parent[i]);
			// path compression
			parent[i] = root;
			return root;
		}
	}
	void union(int i, int j) {
		auto ir = find(i);
		auto jr = find(j);
		if (ir != jr) {
			// union by size
			if (size[ir] > size[jr]) {
				parent[jr] = ir;
				size[ir] += size[jr];
			} else {
				parent[ir] = jr;
				size[jr] += size[ir];
			}
		}
	}
};
class Solution {
public:
	vector<vector<string>> accountMerge(vector<vector<string>>& accounts) {
		UnionFind uf;
		map<string, string> accountname_m;
		for (auto vec: accounts) {
			string s = vec[1];
			accountname_m[s] = vec[0];
			uf.add(s, -1);
			int p = uf.m[s];
			for (int i=2; i< vec.size(); ++i) {
				s = vec[i];
				uf.add(s, p);
			}
		}
		vector<vector<string>> ret;
		map<int, int> partition;
		for (int i=0; i<uf.reversem.size(); ++i) {
			string s = uf.reversem[i];
			int root = uf.find(i);
			if (root == i) {
				partition[root] = ret.size();
				ret.push_back({accountname_m[s], s});
			}
		}
		for (int i=0; i<uf.reversem.size(); ++i) {
			string s = uf.reversem[i];
			int root = uf.find(i);
			if (root != i) {
				int id = partition[root];
				ret[id].push_back(s);
			}
		}
		for (int i=0; i<ret.size(); ++i) {
			sort(ret[i].begin()+1, ret[i].end());
		}
		return ret;
	}
};
