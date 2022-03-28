class Solution {
public:
    // int lengthOfLongestSubstring(string s) {
    //     // if(s == " ") return 1;
    //     // bool arr[26] = {false};
    //     int start = 0, end = 0;
    //     int len = 0, count = 0;
    //     unordered_map<char, int> map;
    //     while(start < s.size() && end < s.size()) {
    //         if(map.find(s[end]) == map.end()) {
    //         //if(arr[((int) s[end])-((int) 'a')] == false) {
    //             map[s[end]]++;
    //             //arr[s[end]-'a'] = true;
    //             count++;
    //             end++;
    //             len = max(len, count);
    //         }
    //         else {
    //             while(s[start] != s[end]) {
    //                 start++;
    //             }
    //             map.clear();
    //             //memset(arr, false, sizeof(arr));
    //             count = 0;
    //             start++;
    //             end = start;
    //         }
    //     }
    //     return len;
    // }
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int start = 0, end = 0;
        int length = 0, ans = 0;
        while(start < s.size() && end < s.size()) {
            if(charSet.find(s[end]) == charSet.end()){
                charSet.insert(s[end]);  
                end++;
                length++;
            }
            else {
                while(charSet.find(s[end]) != charSet.end()) {
                    charSet.erase(s[start]);
                    start++;
                }
                length = end-start;
            }
            ans = max(length, ans);
        }
        return ans;
    }
};