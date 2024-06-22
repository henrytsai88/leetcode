class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int odd = 0, count = 0, res = 0;
        for (int left = 0, right = 0; right < nums.size(); right++) {
            if (nums[right] & 1) {
                odd++;
                if (odd >= k) {
                    count = 0;
                    while (true) {
                        count++;
                        if (nums[left++] & 1) break;
                    }
                    res += count;
                }
            }
            else if (odd >= k) res += count;
        }
        return res;
    }
};