class Solution {
public:
//     string removeDuplicates(string s, int k) {
//         return "";
//         bool flag = false;
//         do {
//             int i=0, j=1;
//             flag = false;
//             while(i <= j && j < s.size()) {
//                 if(j-i < k-1) {
//                     if(s[j] != s[i]) i = j;
//                 }
//                 else if(j-i == k-1) {
//                     if(s[j] == s[i]) {
//                         while(j >= i) {
//                             s.erase(j, 1);
//                             j--;
//                         }
//                         // s.erase(i, k);
//                         // j = i;
//                         j++;
//                         flag = true;
//                     }
//                     else i = j;
//                 }
//                 j++;
//             }
//         } while(flag == true);
//         return s;
//     }
// };
    
//     string removeDuplicates(string s, int k) {
//         stack<char> stk;
//         if(s == "" || k > s.size()) return s;
//         bool flag = false;
        
//         do {
//             flag = false;
//             int count = 0;
//             stk.push(s[0]);
//             for(int i=1; i<s.size(); i++) {
//                 if(!stk.empty() && s[i] == stk.top()) {
//                     count++;
//                     if(count == k-1) {
//                         while(count > 0) {
//                             stk.pop();
//                             count--;
//                         }
//                         flag = true;
//                         i++;
//                     }
//                 }
//                 else count = 0;
//                 if(i < s.size()) stk.push(s[i]);
//             }
//             //string res = "";
//             s.clear();
//             if(stk.empty()) break;
//             while(!stk.empty()) {
//                 //res = res + stk.top();
//                 s = s + stk.top();
//                 stk.pop();
//             }
//             //reverse(res.begin(), res.end());
//             reverse(s.begin(), s.end());
//             //s = res;
//         } while(flag == true);

//         return s;
//     }
// };
    
    string removeDuplicates (string s, int k) {
        stack<pair<char, int>> stk;
        if(k > s.size()) return s;
        
        for(int i=0; i<s.size(); i++) {
            if(stk.empty() || stk.top().first != s[i]) {
                stk.push({s[i], 1});
            }
            else if(stk.top().first == s[i]) {
                stk.top().second++;
                if(stk.top().second == k){
                    stk.pop();
                }
            }
        }
        
        string res = "";
        while(!stk.empty()) {
            res.append(stk.top().second, stk.top().first);
            stk.pop();
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};