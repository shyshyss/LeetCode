#include<iostream>
#include<queue>
//使用双向队列deque存储窗口中的最大元素，使deque的队首元素为每个窗口的最大元素
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        if (nums.size() == 0 || k == 0) return res;
        deque<int>deq;
        int i;
        //形成窗口前
        for (i = 0; i < k; i++) {
            while (!deq.empty() && deq.back() < nums[i]) {
                deq.pop_back();
            }
            deq.push_back(nums[i]);
        }
        res.push_back(deq.front());
        //形成窗口后
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
