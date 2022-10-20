#include<iostream>
#include<queue>

using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        if (nums.size() == 0 || k == 0) return res;
        deque<int>deq;
        int i;
        for (i = 0; i < k; i++) {
            while (!deq.empty() && deq.back() < nums[i]) {
                deq.pop_back();
            }
            deq.push_back(nums[i]);
        }
        res.push_back(deq.front());
        for (i = k; i < nums.size(); i++) {
            if (deq.front() == nums[i - k ]) {
                deq.pop_front();
            }
            while (!deq.empty() && deq.back() < nums[i]) {
                deq.pop_back();
            }
            deq.push_back(nums[i]);
            res.push_back(deq.front());
        }
        return res;
    }
};