class Solution {
public:
    bool validPalindrome(string s) {
        // unordered_set<char> charSet;
        // for(int i=0; i<s.size(); i++) {
        //     if(charSet.find(s[i]) != charSet.end()) 
        //         charSet.erase(s[i]);
        //     else 
        //         charSet.insert(s[i]);
        // }
        // if(charSet.size() > 2) return false;
        // else return true;
        int start = 0, end = s.size()-1;
        int count = 0;
        while(start < end) {
            if(s[start] == s[end]) {
                start++;
                end--;
            }
            else {
                if(s[start+1] == s[end]) {
                    string temp = s;
                    temp.erase(start, 1);
                    string temp2 = temp;
                    reverse(temp.begin(), temp.end());
                    if(temp2 == temp) {
                        //count++;
                        // start = start + 2;
                        // end--;
                        // continue;
                        return true;
                    }
                }
                if(s[start] == s[end-1]) {
                    string temp = s;
                    temp.erase(end, 1);
                    string temp2 = temp;
                    reverse(temp.begin(), temp.end());
                    if(temp2 == temp) {
                        // count++;
                        // start++;
                        // end = end - 2;
                        // continue;
                        return true;
                    }
                }
                // count += 2;
                // start++;
                // end--;
                return false;
            }
        }
        // if(count > 1) return false;
        // else return true;
        return true;
    }
};