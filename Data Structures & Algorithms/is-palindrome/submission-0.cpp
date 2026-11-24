class Solution {
public:
    bool is_alphanumeric(const char a) {
        return (a > 47 && a < 58) || (a > 64 && a < 91) ||  (a > 96 && a < 123);
    }
    bool equal_ignore_case(const char a, const char b) {
        if(a < 58 || b < 58)
            return a == b;
        return a == b || (a+32) == b || (a-32) == b;
    }
    bool isPalindrome(string s) {
        const char* front = s.c_str();
        const char* back = front + s.length() * sizeof(char);
        while(front < back) {
            if(!is_alphanumeric(*front)) {
                front += sizeof(char);
                continue;
            }
            if(!is_alphanumeric(*back)) {
                back -= sizeof(char);
                continue;
            }
            if(!equal_ignore_case(*front, *back))
                return false;
            front += sizeof(char);
            back -= sizeof(char);
        }
        return true;
    }
};
