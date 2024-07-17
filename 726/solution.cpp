class Solution {
public:
    void merge(map<string, int>& m, map<string, int>& counts, int times) {
        for (auto p : counts) {
            m[p.first] += p.second * times;
        }
    }
    int parseDigits(string& s, int& i) {
        int i0 = i;
        while (i < s.size() && isdigit(s[i])) i++;
        return i == i0 ? 1 : stoi(s.substr(i0, i - i0));
    }
    map<string, int> parseUnit(string& s, int& i) {
        map<string, int> counts;
        if (s[i] == '(') {
            map<string, int> c = parseFormula(s, ++i);
            int digits = parseDigits(s, ++i);
            merge(counts, c, digits);
        }
        else {
            int i0 = i++;
            while (i < s.size() && islower(s[i])) i++;
            string atom = s.substr(i0, i - i0);
            int digits = parseDigits(s, i);
            counts[atom] += digits;
        }
        return counts;
    }
    map<string, int> parseFormula(string& s, int& i) {
        map<string, int> m;
        while (i < s.size() && s[i] != ')') {
            map<string, int> counts = parseUnit(s, i);
            merge(m, counts, 1);
        }
        return m;
    }
    string countOfAtoms(string formula) {
        string res;
        int i = 0;
        map<string, int> m = parseFormula(formula, i);
        for (auto p : m) {
            res += p.first;
            if (p.second > 1) res += to_string(p.second);
        }
        return res;
    }
};