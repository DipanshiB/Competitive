class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        for(int i=0; i<arr.size(); i++) {
            int ideal = round(((double)target) / n);
            if(arr[i] < ideal) {
                target = target - arr[i];
                n--;
                continue;
            }
            else {
                if(abs(target - ideal*n) >= abs(target - (ideal-1)*n))
                    ideal = ideal-1;
                if(abs(target - ideal*n) > abs(target - (ideal+1)*n))
                    ideal = ideal+1;
                return ideal;
            }
        }
        return arr.back();
    }
};