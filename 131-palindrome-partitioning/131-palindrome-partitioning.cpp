class Solution {
public:

    bool isPal(string s) {
        if(s[0] != s[s.size()-1]) return false;
        string t = s;
        reverse(t.begin(), t.end());
        if(t == s) return true;
        else return false;
    }
    
    void helper(int index, string s, vector<string>& temp, vector<vector<string>>& res) {
        if(index == s.size()) {
            res.push_back(temp);
            return;
        }
        
        for(int i=index; i<s.size(); i++) {
            if(isPal(s.substr(index, i-index+1))) {
                temp.push_back(s.substr(index, i-index+1));
                helper(i+1, s, temp, res);
                temp.pop_back();
            }
        }
        return;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        helper(0, s, temp, res);
        return res;
    }
};