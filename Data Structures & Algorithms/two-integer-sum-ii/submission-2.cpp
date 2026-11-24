class Solution {
public:
    int binary_search(vector<int>& numbers, int value, int ignore) {
        int start = 0;
        int end = numbers.size()-1;
        while(start <= end) {
            int j = (end+start)/2;
            if(numbers[j] == value) {
                if(j != ignore)
                    return j;
                else if(j+1 <= end && numbers[j+1] == value)
                    return j+1;
                else if(j-1 >= start && numbers[j-1] == value)
                    return j-1;
            } else if(numbers[j] < value) {
                start = j+1;
            } else {
                end = j-1;
            }
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0; i < numbers.size(); ++i) {
            int second = target - numbers[i];
            int j = binary_search(numbers, second, i);
            if(j != -1) {
                vector<int> ret = {i+1, j+1};
                return ret;
            }
        }
    }
};
