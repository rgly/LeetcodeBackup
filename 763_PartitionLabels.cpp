// Time : Beats 100%
// Memory : Beats 87.66%
class Solution {
public:
	vector<int> partitionLabels(string s) {
		// label -> partition_id
		// labels only contains 26 lower English letters
		array<int, 26> partID;
		std::fill(partID.begin(), partID.end(), -1);
		// partition_id
		vector<int> partSize;
		const int inta = static_cast<int>('a');
		for (char c: s) {
			int id = static_cast<int>(c) - inta;
			int pid = partID[id];
			if (pid == -1) {
				partID[id] = partSize.size();
				partSize.push_back(1);
			} else if (pid == partSize.size()-1) {
					partSize[pid] += 1;
			} else {
				for (int i=0; i<26; ++i) {
					partID[i] = min(pid, partID[i]);
				}
				int sum = 1;
				for (int i=pid; i<partSize.size(); ++i) {
					sum += partSize[i];
				}
				partSize[pid] = sum;
				partSize.resize(pid+1);
			}
		}
		return partSize;
	}
};
