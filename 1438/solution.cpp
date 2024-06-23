class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxdq, mindq;
        int left = 0, right;
        for (right = 0; right < nums.size(); right++) {
            while (!maxdq.empty() && nums[right] > maxdq.back()) maxdq.pop_back();
            while (!mindq.empty() && nums[right] < mindq.back()) mindq.pop_back();
            maxdq.push_back(nums[right]);
            mindq.push_back(nums[right]);
            if (maxdq.front() - mindq.front() > limit) {
                if (maxdq.front() == nums[left]) maxdq.pop_front();
                if (mindq.front() == nums[left]) mindq.pop_front();
                left++;
            }
        }
        return right - left;
    }
};