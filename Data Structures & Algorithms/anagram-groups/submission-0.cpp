class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        int n = s.size();
        vector<vector<int>> v(n,vector<int>(26, 0));
        for(int i=0;i<n;i++){
            for(int j = 0;j<s[i].size();j++){
                v[i][s[i][j]-'a']++;
            }
        }

        map<vector<int>, vector<string>> mp;

        for(int i=0;i<n;i++){
            auto itr = mp.find(v[i]);
            if(itr == mp.end()){
                mp[v[i]].push_back(s[i]);
            } else {
                itr->second.push_back(s[i]);
            }
        }

        vector<vector<string>> vv;
    
        for(auto x:mp){
            vv.push_back(x.second);
        }
        return vv;

    }
};
