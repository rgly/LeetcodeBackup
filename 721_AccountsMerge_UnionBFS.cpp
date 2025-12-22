// Assuming no duplicated email
// Assuming email not sorted
class Solution {
public:
	// sorted array
	// complexity log(n) ^ 2
	typedef vector<string>::iterator ItTy;
	bool IsOverlap(ItTy a,  ItTy ae,
				 				ItTy b,  ItTy be){
		if (a == ae || b == be) return false;
		if (a+1 == ae) {
			return binary_search(b, be, *a);
		}
		if (b+1 == be) {
			return binary_search(a, ae, *b);
		}

		// assuming longer a
		ItTy mid = a + distance(a, ae)/2;
		auto bit = lower_bound(b, be, *mid);
		if (bit == be) {
			return IsOverlap(a, mid, b, be);
		} else if (*bit == *mid) return true;

		return IsOverlap(a, mid, b, bit)
		 || IsOverlap(mid+1, ae, bit, be);
	}
	bool IsOverlap(vector<vector<string>>& accounts, int i, int j) {
		return IsOverlap(
			accounts[i].begin()+1, accounts[i].end(),
			accounts[j].begin()+1, accounts[j].end());
	}
		
	// returned email must be sorted
	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
		for (int i=0; i< accounts.size(); ++i) {
			sort(accounts[i].begin()+1, accounts[i].end());
		}
		vector<vector<bool>> link(accounts.size(),
							vector<bool>(accounts.size()));
		for (int i=0; i< accounts.size()-1; ++i) {
			link[i][i] = true;
			for (int j=i+1; j< accounts.size(); ++j) {
				link[j][i] = IsOverlap(accounts, i, j);
				link[i][j] = link[j][i];
			}
		}
		set<int> s;
		for (int i=0; i< accounts.size(); ++i) {
			 s.insert(i);
		}
		vector<vector<string>> ret;
		queue<int> q;
		while (!s.empty()) {
			int id = *s.begin();
			ret.push_back({accounts[id][0]});
			q.push(id);
			while(!q.empty()) {
				int qid = q.front();
				q.pop();
				if (s.count(qid) == 0) continue;
				s.erase(qid);
				ret.back().insert(ret.back().end(),
						accounts[qid].begin()+1,
						accounts[qid].end());
				for (int i=0; i< accounts.size(); ++i) {
					if (link[qid][i] && s.count(i)) {
						q.push(i);
					}
				}
			}
			sort(ret.back().begin()+1, ret.back().end());
			auto it = unique(ret.back().begin()+1, ret.back().end());
			ret.back().erase(it, ret.back().end());
		}
		return ret;
	}
};
