class Solution {
public:
    string find(string s, map<string, string>& parent) {
        if (parent[s] != s) {
            parent[s] = find(parent[s], parent);
        }
        return parent[s];
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, string> owner;
        map<string, string> parent;
        map<string, set<string>> unions;
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                owner[accounts[i][j]] = accounts[i][0];
                parent[accounts[i][j]] = accounts[i][j];
            }
        }
        for (int i = 0; i < accounts.size(); i++) {
            string p = find(accounts[i][1], parent);
            for (int j = 2; j < accounts[i].size(); j++) {
                parent[find(accounts[i][j], parent)] = p;
            }
        }
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                unions[find(accounts[i][j], parent)].insert(accounts[i][j]);
            }
        }
        vector<vector<string>> res;
        for (auto& p : unions) {
            vector<string> emails(p.second.begin(), p.second.end());
            emails.insert(emails.begin(), owner[p.first]);
            res.push_back(emails);
        }
        return res;
    }
};