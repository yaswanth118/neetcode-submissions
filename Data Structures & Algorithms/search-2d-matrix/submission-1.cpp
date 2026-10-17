class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int l = -1;
        int r = a.size();
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (a[mid][0] <= target) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if (l == -1) {
            return false;
        }
        int ly = -1, ry = a[l].size();
        while (ly + 1 < ry) {
            int mid = (ly + ry) / 2;
            if (a[l][mid] <= target) {
                ly = mid;
            } else {
                ry = mid;
            }
        }
        if (ly == -1) {
            return false;
        }
        return a[l][ly] == target ? true : false;
    }
};
