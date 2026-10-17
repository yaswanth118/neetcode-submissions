class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& v) {
        sort(v.begin(), v.end());
        int n = v.size();
        set<vector<int>> ans;
        for (int i = 0; i < v.size(); i++) {
            int l = i + 1;
            int r = n - 1;
            int target  = -1 * v[i];
            while (l < r) {
                if(v[l] + v[r] > target ){
                    r--;
                } else if(v[l] + v[r] < target) {
                    l++;
                } else {
                    // cout << v[l] + v[r] << " " << target << endl;
                    // set<int> s = 
                    ans.insert({v[i], v[l], v[r]});
                    l++;
                    r--;
                }
            }
        }
        vector<vector<int>> f_ans;
        for(auto x: ans){
            f_ans.push_back(x);
        }
        return f_ans;
    };
};
