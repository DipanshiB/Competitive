/*
Given n groups of singers(as an array of size n with arr[i] denoting the ith group size) and m microphones available, we had to output the minimum largest group size sharing a single mic. 
A group could only be divided into two further groups at a time(i.e, in a single division, only two subgroups could be formed. 
Further these subgroups could also be divided using the same approach). 
The approach was to use a binary search and check for the optimality of the group size. 
Eg: input :[100, 60, 80, 40, 30] , m=9 output:40 (groups after division could be as follows [40,40,20,40,20,40,40,40,30]) Time Complexity: O(nlogn)
*/
// O(n^2)

#include <bits/stdc++.h>
void divideLargestGroup(vector<int>& arr, vector<int>& brr){
    int ix, mx = -1;
    for(int i=0; i<arr.size(); i++){
        if(mx < ceil(arr[i]/(brr[i]+1))){
            mx = ceil(arr[i]/(brr[i]+1));
            ix = i;
        }
    }
    brr[ix]++;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n = 5, m = 9; //input
    vector<int> arr = {100,30,60,80,40}; //input
    sort(arr.begin(),arr.end()); //not needed
    vector<int> brr(n,0);
    for(int t=0; t<m-n; t++) divideLargestGroup(arr,brr);
    int ans = -1;
    for(int i=0; i<arr.size(); i++){
        if(ans < ceil(arr[i]/(brr[i]+1))) ans = ceil(arr[i]/(brr[i]+1));
    }
    cout << ans; //output
    return 0;
}