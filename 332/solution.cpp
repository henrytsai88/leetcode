class Solution {
public:
    map<string, multiset<string>> targets;
    vector<string> route;
    void dfs(string airport) {
        while (targets[airport].size()) {
            string next = *targets[airport].begin();
            targets[airport].erase(targets[airport].begin());
            dfs(next);
        }
        route.push_back(airport);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (vector<string>& ticket : tickets) {
            targets[ticket[0]].insert(ticket[1]);
        }
        dfs("JFK");
        return vector<string>(route.rbegin(), route.rend());
    }
};