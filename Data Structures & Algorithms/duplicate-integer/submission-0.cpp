class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(auto x:nums){
            if(s.find(x) == s.end()) {
                s.insert(x);
            } else {
                return true;
            }
        }
        return false;
    }
};