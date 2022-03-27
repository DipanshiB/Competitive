class Solution {
public:
    int firstUniqChar(string s) {
        vector<pair<int, int>> vec(26, {-1,0});
        for(int i=0; i<s.size(); i++) {
            int freq = vec[s[i]-'a'].second + 1;
            vec[s[i]-'a'] = make_pair(i, freq);
        }
        int index = INT_MAX;
        for(int i=0; i<26; i++) {
            if(vec[i].second == 1 && vec[i].first < index) {
                index = vec[i].first;
            }
        }
        if(index == INT_MAX) return -1;
        else return index;
    }
};