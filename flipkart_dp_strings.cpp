/*
A person can create a flower bouquet with either 3 roses (cost of bouquet = p) or 1 rose and 1 lily (cost = q)
In an array of flowers, the person has to select contiguous set of flowers i.e. 2 or 3 to gain maximum cost.

Input format: A string of 0(denotes rose) and 1(denotes lily).
Output : Maximum cost.

Example:
Input: p = 2, q = 3, s = 0001000
Output: 5
*/
// Top Down Memoization O(n)
int p = 2, q = 3; //input
#include <bits/stdc++.h>
int recurse(string s, int i, vector<int>& t){
    int n = s.size();
    if(i <= 0) return t[0] = 0;
    if(t[i] != -1) return t[i];
    int mx = INT_MIN;
    if(i>=3 && s[i-1] == s[i-2] == s[i-3] == '0'){
        mx = max(mx, recurse(s,i-3,t) + p);
    } 
    if(i>=2 && s[i-1] != s[i-2]){
        mx = max(mx, recurse(s,i-2,t) + q) ;
    }
    if(i>=1){
        mx = max(mx, recurse(s,i-1,t));
    }
    return t[i] = mx;
}

int main() {
    string s = "0001000"; //input
    int n = s.size();
    vector<int> t(n+1, -1);
    recurse(s,n,t);
    cout << t[n];
    return 0;
}