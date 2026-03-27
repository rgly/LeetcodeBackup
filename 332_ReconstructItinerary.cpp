// Time : Beats 91.27%
// Memory : Beats 40.62%
// The code base is refered to vanAmsen's solution
// The key idea is that arbitary DFS flow would eventually
// go to the same last airport.
class Solution {
public:
	vector<string> findItinerary(vector<vector<string>>& tickets) {
ctor<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> graph;
        
        for (auto& ticket : tickets) {
            graph[ticket[0]].push_back(ticket[1]);
        }
        
        for (auto& [_, destinations] : graph) {
            sort(destinations.rbegin(), destinations.rend());
        }
        
        vector<string> itinerary;
        
		// lambda with capture graph & itinerary, also
		// using "this" for recursion
		auto dfs = [&graph, &itinerary]
					(this auto&& self, const string& airport) -> void {
            while (!graph[airport].empty()) {
                string next = graph[airport].back();
                graph[airport].pop_back();
                self(next);
            }
            itinerary.push_back(airport);
		};
        
        dfs("JFK");
        reverse(itinerary.begin(), itinerary.end());
        
        return itinerary;
	}
};
