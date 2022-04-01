class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0, end = s.size()-1;
        while (start < end) {
            // char c = s[start];
            // s[start] = s[end];
            // s[end] = c;
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};