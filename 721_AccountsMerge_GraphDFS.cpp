// Assuming no duplicated email
// Assuming email not sorted
class Solution {
public:
	void dfs(vector<vector<bool>>& links, int id,
				vector<bool>& used, vector<int>& ret) {
		if (used[id]) return;
		ret.push_back(id);
		used[id] = true;
		for (int i=0; i<used.size(); ++i) {
			if (links[id][i]) {
				dfs(links, i, used, ret);
			}
		}
	}
		
	// returned email must be sorted
	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
		map<string, int> emailmap;
		vector<string> emails;
		for (int i=0; i< accounts.size(); ++i) {
			for (int j=1;j< accounts[i].size(); ++j) {
				string e = accounts[i][j];
				if (emailmap.count(e) == 0) {
					emailmap[e] = emails.size();
					emails.push_back(e);
				}
			}
		}
		const int n = emails.size();
		vector<bool> used(n, false);
		vector<vector<bool>> links(n, vector<bool>(n, false));
		for (int i=0; i< accounts.size(); ++i) {
			int id0 = emailmap[accounts[i][1]];
			for (int j=1;j< accounts[i].size(); ++j) {
				string e = accounts[i][j];
				int id = emailmap[e];
				links[id0][id] = true;
				links[id][id0] = true;
			}
		}

		vector<vector<string>> ret;
		for (auto& v: accounts) {
			auto name = v[0];
			int i = emailmap[v[1]];
			if (used[i]) continue;

			vector<int> buf;
			dfs(links, i, used, buf);

			vector<string> buf2(1, name);
			for (auto j : buf) buf2.push_back(emails[j]);
			sort(buf2.begin()+1, buf2.end());
			ret.push_back(buf2);
		}
		return ret;
	}
};
