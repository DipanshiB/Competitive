class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string first = strs[0];
        int count = 0;
        bool flag = true;
        int n = strs.size(), k = first.size();
        for(int i=0; i<k; i++) {
            for(int j=1; j<n; j++) {
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
    
    // string longestCommonPrefix(vector<string>& strs) {
    //     sort(strs.begin(), strs.end());
    //     string first = strs[0];
    //     string last = strs[strs.size()-1];
    //     int count = 0;
    //     for(int i=0; i<first.size(); i++) {
    //         if(first[i] == last[i])
    //             count++;
    //         else break;
    //     }
    //     return first.substr(0, count);
    // }
};