class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> record;
        for(int i=0; i<ops.size(); i++) {
            if(isdigit(ops[i][0]) || ops[i][0] == '-'){
                record.push_back(stoi(ops[i]));
            }
            else if(ops[i] == "C") {
                record.pop_back();
            }
            else if(ops[i] == "D") {
                record.push_back(record[record.size() - 1] * 2);
            }
            else if(ops[i] == "+") {
                record.push_back(record[record.size()-1] + record[record.size()-2]);
            }
        }
        int sum = 0;
        for(int i=0; i<record.size(); i++) {
            sum += record[i];
        }
        return sum;
    }
};