class Solution {
public:
    bool isValid(string s) {
        vector<char> stack = {};
        const char* arr = s.c_str();
        for(int i = 0; i < s.length(); ++i) {
            if(arr[i] == '(' || arr[i] == '{' || arr[i] == '[')
                stack.push_back(arr[i]);
            else if(stack.size() == 0)
                return false;
            else if(arr[i] == ')' && stack[stack.size()-1] == '(' ||
                    arr[i] == '}' && stack[stack.size()-1] == '{' ||
                    arr[i] == ']' && stack[stack.size()-1] == '[')
                stack.pop_back();
            else
                return false;
        }
        return stack.empty();
    }
};
