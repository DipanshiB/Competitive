class Solution {
public:
    
    static bool comp(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freqMap;
        vector<pair<int, int>> freqVector;
        for(int i=0; i<nums.size(); i++) {
            freqMap[nums[i]]++;
        }
        for(auto elem : freqMap) {
            freqVector.push_back({elem.first, elem.second});
        }
        sort(freqVector.begin(), freqVector.end(), comp);
        vector<int> result;
        for(int i=0; i<k; i++) {
            result.push_back(freqVector[i].first);
        }
        return result;
    }
};