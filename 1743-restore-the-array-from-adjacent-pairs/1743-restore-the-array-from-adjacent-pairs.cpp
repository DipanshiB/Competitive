class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size();
        vector<int> result;
        if(n == 0) return result;
        if(n == 1) return adjacentPairs[0];
        unordered_map<int, vector<int>> adjList;
        for(int i=0; i<n; i++) {
            adjList[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            adjList[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }
        unordered_set<int> visited;
        queue<int> q;
        for(auto elem : adjList) {
            if(elem.second.size() == 1) {
                q.push(elem.first);
                break;
            }
        }
        while(!q.empty()) {
            int val = q.front();
            if(visited.find(val) == visited.end()) {
                result.push_back(val);
                for(auto node : adjList[val]) {
                    if(visited.find(node) == visited.end())
                        q.push(node);
                }
            }
            visited.insert(val);
            q.pop();
        }
        return result;
        
        // unordered_set<int> usedNums;
        // vector<int> result;
        // if(adjacentPairs.size() == 0) return result;
        // if(adjacentPairs.size() == 1) return adjacentPairs[0];
        // for(int i=0; i<adjacentPairs.size(); i++) {
        //     int a = adjacentPairs[i][0], b = adjacentPairs[i][1];
        //     if(usedNums.find(a) == usedNums.end() && usedNums.find(b) == usedNums.end()) {
        //         result.push_back(a);
        //         usedNums.insert(a);
        //         result.push_back(b);
        //         usedNums.insert(b);
        //     }
        //     else if(usedNums.find(a) != usedNums.end() && usedNums.find(b) == usedNums.end()) {
        //         for(int j=0; j<result.size(); j++) {
        //             if(result[j] == a) {
        //                 if(j==0) result.insert(result.begin(), b);
        //                 else result.insert(result.begin()+j+1, b);
        //                 usedNums.insert(b);
        //                 break;
        //             }
        //         }
        //     }
        //     else if(usedNums.find(a) == usedNums.end() && usedNums.find(b) != usedNums.end()) {
        //         for(int j=0; j<result.size(); j++) {
        //             if(result[j] == b) {
        //                 if(j==0) result.insert(result.begin(), a);
        //                 else result.insert(result.begin()+j+1, a);
        //                 usedNums.insert(a);
        //                 break;
        //             }
        //         }
        //     }
        //     else {
        //         int posA, posB;
        //         for(int j=0; j<result.size(); j++) {
        //             if(result[j] == a) posA = j;
        //             if(result[j] == b) posB = j;
        //         }
        //         if(posA < posB) {
        //             result[posA] = result[posA+1];
        //             result[posA+1] = a;
        //         }
        //         else {
        //             result[posB] = result[posB+1];
        //             result[posB+1] = b;
        //         }
        //     }
        // }
        // return result;

    }
};