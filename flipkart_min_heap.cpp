/*
Given an array of N elements, choose 2 elements and add a + b to result, as well as insert a + b – 1 back to array.
Repeat the same for N – 1 times. Find the minimum value of the result.
*/

// 0(n log n) time
#include <bits/stdc++.h>
int main() {
    int n = 4; vector<int> arr = {4,3,2,1}; //input
    int ans = 0, t1,t2;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0; i<arr.size(); i++) pq.push(arr[i]);
    for(int i=0; i<arr.size()-1; i++){
        t1 = pq.top(); pq.pop();
        t2 = pq.top(); pq.pop(); 
        ans += t1+t2;
        pq.push(t1+t2-1); //logn time
    }
    cout << ans;
    return 0;
}