class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> m;
        for (int num : arr1) m[num]++;
        int i = 0;
        for (int num : arr2) {
            while (m[num]--) {
                arr1[i++] = num;
            }
            m.erase(num);
        }
        for (auto p : m) {
            while (p.second--) {
                arr1[i++] = p.first;
            }
        }
        return arr1;
    }
};