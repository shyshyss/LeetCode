#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size()-1, nums.size()-k);
    }
    int quickSelect(vector<int>& nums, int low, int high,int k) {
        if (low > high) {
            return 0;
        }
        int i = low;
        int j = high;
        int key = nums[i];
        while (i < j) {
            while (nums[j] >= key && i < j) {
                j--;
            }
            nums[i] = nums[j];
            while (nums[i] <= key && i < j) {
                i++;
            }
            nums[j] = nums[i];
        }
        if (i < k) {
            return quickSelect(nums, i + 1, high,k);
        }
        else if (i == k) {
            return key;
        }
        else {
            return quickSelect(nums, low, i - 1, k);
        }

    }
};

void main()
{

}