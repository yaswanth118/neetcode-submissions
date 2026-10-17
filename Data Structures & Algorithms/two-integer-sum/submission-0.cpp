class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]] = i;
        }
        
        for(int i=0;i<n;i++){
            auto itr = mp.find(target - nums[i]);
            if(itr != mp.end()){
                if(itr->second == i){
                    continue;
                } else {
                    return {min(itr->second, i), max(itr->second, i)};
                }
            }
        }
    }
};
