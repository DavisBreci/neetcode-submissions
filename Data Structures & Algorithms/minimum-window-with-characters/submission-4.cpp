class Solution {
public:
    // vector<int> substringChecksum(const char* uarr, int startIndex, int endIndex) {
    //     vector<int> checksum(256,0);
    //     for(int i = startIndex; i <= endIndex; ++i) {
    //         checksum[static_cast<int>(uarr[i])]++;
    //     }
    //     return checksum;
    // }
    void printChecksum(vector<int> cs) {
        for(int i = 97; i < 123; ++i) {
            cout << static_cast<char>(i) << ": " << cs[i] << endl;
        }
        cout << endl;
    }

    bool vecDiffHasNegative(vector<int> x, vector<int> y) {
        for(int i = 0; i < x.size(); i++)
            if(x[i] - y[i] < 0)
                return true;
        return false;
    }
    string minWindow(string s, string t) {
        const char* sarr = s.c_str();
        const char* tarr = t.c_str();
        vector<int> tchecksum(256,0);
        for(int i = 0; i < t.length(); ++i)
            tchecksum[static_cast<int>(tarr[i])]++;
        string result = "";
        vector<int> schecksum(256,0);
        int startIndex = 0;
        int endIndex = -1;
        
        for(int i = 0; i < s.length(); ++i) {
            schecksum[static_cast<int>(sarr[i])]++;
            if(!vecDiffHasNegative(schecksum, tchecksum)) {
                endIndex = i;
                break;
            }
        }
        if(endIndex == -1)
            return result;
        
        int i = startIndex;
        int j = endIndex;
        // while(j < s.length()) {
        //     if(!vecDiffHasNegative(substringChecksum(sarr, i+1, j), tchecksum)) {
        //         startIndex = i+1;
        //         endIndex = j;
        //     } else {
        //         j++;
        //     }
        //     i++;
        // }
        
        while(true) {
            schecksum[static_cast<int>(sarr[i])]--;
            if(!vecDiffHasNegative(schecksum, tchecksum)) {
                startIndex = i+1;
                endIndex = j;
            } else {
                j++;
                if(j >= s.length())
                    break;
                schecksum[static_cast<int>(sarr[j])]++;
            }
            i++;
        }
        return s.substr(startIndex, endIndex - startIndex + 1);
    }
};
