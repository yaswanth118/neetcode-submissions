class Solution {
   public:
    int search(vector<int>& v, int target) {
        int l = -1;
        int r = v.size();
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (v[mid] <= target) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l == -1 || v[l] == target ? l : -1;
    }
};
