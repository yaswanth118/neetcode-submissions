class Solution {
public:
    vector<vector<int>> subsets(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> ans;
        for(int i=0;i<(1<<n);i++){
            vector<int>v;
            for(int j=0;j<10;j++){
                if(1<<j & i) {
                    v.push_back(a[j]);
                }
            }
            ans.push_back(v);
        }
        return ans;
        
    }

};
