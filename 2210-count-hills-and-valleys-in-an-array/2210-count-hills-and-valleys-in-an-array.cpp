class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i=0; i<nums.size(); i++) {
            if(i == 0 || i == n-1) continue;
            if(nums[i] == nums[i-1]) continue;
            //get closest non same number to the left
            int j = i;
            while(j >= 0 && nums[i] == nums[j]) {
                j--;
            }
            //get closest non same number to the right
            int k = i;
            while(k <= n-1 && nums[i] == nums[k]) {
                k++;
            }
            if(j < n && j >= 0 && k < n && k >= 0 && nums[i] < nums[k] && nums[i] < nums[j]) count++;
            if(j < n && j >= 0 && k < n && k >= 0 && nums[i] > nums[k] && nums[i] > nums[j]) count++;
        }
        return count;
    }
};