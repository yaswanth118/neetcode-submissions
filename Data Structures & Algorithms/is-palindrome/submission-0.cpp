class Solution {
   public:
    bool isAlphaNumeric(char c) {
        if (c >= 'A' && c <= 'Z') {
            return true;
        }
        if (c >= 'a' && c <= 'z') {
            return true;
        }
        if (c >= '0' && c <= '9') {
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        string t = "";
        for(int i=0;i<s.size();i++){
            if(isAlphaNumeric(s[i])){
                if(s[i] >= 'A' && s[i] <='Z') {
                    t.push_back(s[i] - 'A' + 'a');
                } else {
                    t.push_back(s[i]);   
                }
                
            }
        }

        
        string rt = t;
        cout<<rt<<endl;
        reverse(t.begin(),t.end());
        cout<<t<<endl;
        for(int i=0;i<t.size();i++){
            if(t[i]!=rt[i]) return false;
        }
        return true;
    }
};
