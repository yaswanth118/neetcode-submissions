class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        int n = v.size();
        vector<int> ans;
        map<int,int> mp;
        for(int i=0;i<k;i++){
            mp[v[i]]++;
        }
        ans.push_back(mp.rbegin()->first);
        for(int i=k;i<n;i++){
            mp[v[i]]++;
            if(mp[v[i-k]] == 1){
                mp.erase(v[i-k]);
            } else {
                mp[v[i-k]]--;
            }            
            ans.push_back(mp.rbegin()->first);
        }
        return ans;

    }
};
