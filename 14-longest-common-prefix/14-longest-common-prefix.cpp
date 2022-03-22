class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string first = strs[0];
        int count = 0;
        bool flag = true;
        for(int i=0; i<first.size(); i++) {
            for(int j=1; j<strs.size(); j++) {
                if(strs[j][i] != first[i]){
                    flag = false;
                     break;
                } 
            }
            if(flag) count++;
            else break;
        }
        return first.substr(0, count);
    }
};