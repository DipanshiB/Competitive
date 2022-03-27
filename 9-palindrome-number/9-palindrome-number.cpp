class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int num = x;
        long long int new_num = 0;
        while(num > 0) {
            new_num = new_num*10 + num%10;
            num = num / 10;
        }
        return new_num == x;
    }
};