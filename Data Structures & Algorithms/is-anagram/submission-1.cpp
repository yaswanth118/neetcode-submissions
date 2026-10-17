class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        for(auto c:s){
            mp[c]++;
        }
        for(auto x:t){
            mp[x]--;
        }
        for(auto a:mp){
            if(a.second !=0){
                return false;
            }
        }
        return true;
    }
};
