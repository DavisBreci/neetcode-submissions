class Solution {
public:

    string encode(vector<string>& strs) {
        vector<unsigned char> header;
        header.push_back(static_cast<unsigned char>(strs.size()));
        string data = "";
        for(string s : strs) {
            header.push_back(static_cast<unsigned char>(s.length()));
            data.append(s);
        }
        string ret(header.begin(), header.end());
        ret.append(data);
        return ret;
    }

    vector<string> decode(string s) {
        int size = static_cast<unsigned char>(s[0]);
        string header = s.substr(1,size);
        string data = s.substr(1+size);
        vector<string> ret;
        int next_string_index = 0;
        for(int i = 0; i < header.size(); i++) {
            int length = static_cast<unsigned char>(header[i]);
            ret.push_back(data.substr(next_string_index, length));
            next_string_index += length;
        }
        return ret;
    }
};
