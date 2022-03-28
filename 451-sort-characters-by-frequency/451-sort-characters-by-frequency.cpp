class Solution {
public:
    
    static bool cmp(pair<char, int>& a, pair<char, int>& b) {
        return a.second > b.second;
    }
    
    string frequencySort(string s) {
        unordered_map<char, int> freqMap;
        for(int i=0; i<s.size(); i++) {
            freqMap[s[i]]++;
        }
        vector<pair<char, int>> freqVector;
        for(auto elem : freqMap) {
            freqVector.push_back(elem);
        }
        sort(freqVector.begin(), freqVector.end(), cmp);
        string res = "";
        for(auto elem : freqVector) {
            res.append(elem.second, elem.first);
        }
        return res;
    }
};