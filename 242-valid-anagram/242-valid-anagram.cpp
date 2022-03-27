class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s == t;
        
        int arr[26] = {0};
        for(int i=0; i<s.size(); i++) {
            arr[s[i]-'a']++;
        }
        for(int i=0; i<t.size(); i++) {
            arr[t[i]-'a']--;
        }
        for(int i=0; i<sizeof(arr)/sizeof(int); i++) {
            if(arr[i] != 0) return false;
        }
        return true;
     }
};