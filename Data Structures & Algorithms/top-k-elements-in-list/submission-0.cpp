class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int,int> frequency;
        vector<vector<int>> buckets(nums.size());
        for(int i : nums) {
            frequency[i]++;
            buckets.at(frequency[i]-1).push_back(i);
        }
        vector<int> ret;
        int last_bucket = buckets.size()-1;
        while(ret.size() < k) {
            for(int j : buckets[last_bucket])
                if(frequency[j] == last_bucket+1)
                    ret.push_back(j);
            last_bucket--;
        }
        return ret;
    }
};
