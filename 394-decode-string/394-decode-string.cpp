class Solution {
public:
    string decodeString(string s) {
        string temp = "";
        for(int i=0; i<s.size(); i++) {
            int num = 0;
            while(isalpha(s[i])) {
                temp.append(1, s[i]);
                i++;
            }
            while(isdigit(s[i])) {
                num = num*10 + (s[i]-'0');
                i++;
            }
            if(s[i] == '[') {
                int count = 1;
                int openingIdx = i+1;
                while(count != 0) {
                    i++;
                    if(s[i] == '[')
                        count++;
                    else if(s[i] == ']')
                        count--;
                }
                int closingIdx = i-1;
                for(int j = 0; j<num; j++) {
                    temp += decodeString(s.substr(openingIdx, closingIdx - openingIdx + 1));
                }
            }
        }
        return temp;
    }
};