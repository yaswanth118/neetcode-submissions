class Solution {
   public:
    int carFleet(int target, vector<int>& p, vector<int>& s) {
        vector<pair<int, int>> ps;
        int n = p.size();
        for (int i = 0; i < n; i++) {
            ps.push_back({p[i], s[i]});
        }
        sort(ps.begin(), ps.end());

        int fc = 0;
        double time = 0.0;
        for (auto itr = ps.rbegin(); itr != ps.rend(); itr++) {
            double cur_time = (target - itr->first + 0.0) / (itr->second + 0.0);
            // cout<< cur_time 
            if(cur_time  <= time ) {
                continue;
            } else {
                fc++;
                time = cur_time;
            }
        }
        return fc;
    }

};
