//Time: Beats 61.24%
//Memory: Beats 97.83%
class Codec {
public:
	string serialize(TreeNode* root) {
		queue<TreeNode*> q;
		q.push(root);
		string ret;
		while(!q.empty()) {
			int size = q.size();
			for (int i=0; i<size; ++i) {
				TreeNode* t = q.front();
				q.pop();
				if (!t) {
					ret += ",\0";
				} else {
					ret += "," + to_string(t->val);
					q.push(t->left);
					q.push(t->right);
				}
			}
		}
		return ret;
	}
	
	int getNextVal(string& data, int& i) {
		int next_comma = data.find(',', i);
		string valstr = data.substr(i, next_comma-i);
		int val = (valstr == "\0") ? INT_MIN : stoi(valstr);
		i = next_comma+1;
		return val;
	}

	TreeNode* deserialize(string data) {
		queue<TreeNode*> q;
		int idx = 1;
		auto val = getNextVal(data, idx);
		if (val == INT_MIN) return nullptr;
		auto* t = new TreeNode(val);
		q.push(t);

		while(!q.empty()) {
			int size = q.size();
			for (int i=0; i<size; ++i) {
				TreeNode* t = q.front();
				q.pop();
				int lval = getNextVal(data, idx);
				int rval = getNextVal(data, idx);
				if (lval == INT_MIN) {
					t->left = nullptr;
				} else {
					auto* l = new TreeNode(lval);
					t->left = l;
					q.push(l);
				}
				if (rval == INT_MIN) {
					t->right = nullptr;
				} else {
					auto* r = new TreeNode(rval);
					t->right = r;
					q.push(r);
				}
			}
		}
		return t;
	}
};
