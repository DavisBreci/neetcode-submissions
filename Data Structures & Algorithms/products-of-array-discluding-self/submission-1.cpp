class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix_products(nums.size());
        vector<int> suffix_products(nums.size());
        vector<int> ret(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            prefix_products[i] = (i == 0 ? 1 : nums[i-1] * prefix_products[i-1]);
            suffix_products[nums.size()-1-i] = (i == 0 ? 1 : nums[nums.size()-i] * suffix_products[nums.size()-i]);
//            cout << "prefix[" << i << "]: " << prefix_products[i] << "\n";
//            cout << "suffix[" << nums.size()-1-i << "]: " << suffix_products[nums.size()-1-i] << "\n";
        }
        for(int i = 0; i < nums.size(); i++) {
            ret[i] = prefix_products[i] * suffix_products[i];
        }
        return ret;
    }
};
