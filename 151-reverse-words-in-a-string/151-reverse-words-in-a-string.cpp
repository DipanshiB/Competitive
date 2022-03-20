class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string res = "";
        int start = 0;
        while(start < n) {
            while(start < n && s[start] == ' ') {
                start++;
            }
            int end = start+1;
            while(end < n && s[end] != ' ') {
                end++;
            }
            string word;
            if(start < n) {
                word = s.substr(start, end-start);   
                
                if(res == "") {
                    res.append(word);
                }
                else {
                    res = word + " " + res;
                }
            }
            start = end+1;
        }
        return res;
    }
};