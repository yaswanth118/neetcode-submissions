class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto x:nums){
            s.insert(x);
        }
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]-1) != s.end()) {
                continue;
            } else {
                int mn = nums[i];
                int ctr = 0;
                while(s.find(mn) !=s.end()) {
                    ctr++;
                    mn++;
                } 
                ans = max(ans,ctr);
            }
        }
        return ans;
    }
};
