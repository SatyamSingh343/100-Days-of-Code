class Solution {
public:
    int singleNumber(vector<int >& nums) {
        int sol = 0;
        for(size_t i = 0; i < nums.size(); i++)
            sol ^= nums[i];
        return sol;
    }
};