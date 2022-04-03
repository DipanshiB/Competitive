class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 0) return;
        for(int i=nums.size()-2; i>=0; i--) {
            int next = nums[i], next_idx = i;
            for(int j=i+1; j < nums.size(); j++) {
                if(nums[j] > nums[i]) {
                    next = nums[j];
                    next_idx = j;
                }
            }
            if(next != nums[i]) {
                int temp = nums[i];
                nums[i] = nums[next_idx];
                nums[next_idx] = temp;
                sort(nums.begin()+i+1, nums.end());
                return;
            }
        }
        sort(nums.begin(), nums.end());
        return;
    }
};