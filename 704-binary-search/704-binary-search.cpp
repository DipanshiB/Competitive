class Solution {
public:
    
    int bin_src(vector<int> &arr, int start, int end, int target) {
        int mid = start+((end-start)/2);
        if(arr[mid] == target) return mid;
        else if(start < end) {
            if(arr[mid] > target) return bin_src(arr, start, mid-1, target);
            else if(arr[mid] < target) return bin_src(arr, mid+1, end, target);
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        if(nums.size() == 1){
            if(nums[0] == target) return 0;
        }
        return bin_src(nums, 0, nums.size()-1, target);  
    }
};