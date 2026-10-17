class Solution {
   public:
    int findMin(vector<int>& v) {
    int n = v.size();
        if (v[0] < v[n - 1]) {
            return v[0];
        }
    
        // you're finding x where
        int l = -1, r = n;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if(v[mid] > v[n-1]) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return v[r];
    }
};
