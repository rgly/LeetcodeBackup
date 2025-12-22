// Time: Beat 73.87%
// Memory: Beat 97.45%
class TimeMap {
public:
	// key : sorted time-value pairs
	unordered_map<string, pair<vector<int>, vector<string> > > m;
	TImeMap() {
	}
	void set(string key, string value, int timestamp) {
		if (m.count(key) == 0) {
			m[key].first.push_back(timestamp);
			m[key].second.push_back(value);
			return;
		}
		int lasttime = m[key].first.back();
		assert(timestamp > lasttime);
		m[key].first.push_back(timestamp);
		m[key].second.push_back(value);
	}
	string get(string key, int timestamp) {
		if (m.count(key)==0) return "";
		auto it = upper_bound(m[key].first.begin(), m[key].first.end(), timestamp);
		if (it == m[key].first.end()) {
			return m[key].second.back();
		} else if (it == m[key].first.begin()) {
			// no value assigned on that time
			return "";
		} else {
			int idx = distance(m[key].first.begin(), it)-1;
			assert(idx >=0);
			return m[key].second.at(idx);
		}
		return "";
	}
};
