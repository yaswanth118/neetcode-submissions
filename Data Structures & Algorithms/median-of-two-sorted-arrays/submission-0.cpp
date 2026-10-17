class Solution {
   public:
    // Looks for the element of `a` whose rank in the merged order is exactly k.
    // countEqual decides the tie-break between equal values of a and b:
    //   false -> equal elements of `b` come AFTER a[mid]  (use when searching a)
    //   true  -> equal elements of `b` come BEFORE a[mid] (use when searching the swapped pair)
    int search(vector<int>& a, vector<int>& b, int k, bool countEqual, bool& found) {
        int n = a.size();
        int m = b.size();
        int l = -1, r = n;
        int lrank = -1;                       // rank of a[l], saved when l moves

        while (l + 1 < r) {
            int mid = (l + r) / 2;
            int target = a[mid];

            // your inner search: how many elements of b come before target
            int lx = -1, rx = m;
            while (lx + 1 < rx) {
                int mx = (lx + rx) / 2;
                if (b[mx] < target || (countEqual && b[mx] == target)) {
                    lx = mx;
                } else {
                    rx = mx;
                }
            }

            int rank = mid + (lx + 1);        // 0-indexed position of a[mid] in merged order
            if (rank <= k) {
                l = mid;
                lrank = rank;
            } else {
                r = mid;
            }
        }

        found = (l != -1 && lrank == k);
        return found ? a[l] : 0;
    }

    int kth(vector<int>& a, vector<int>& b, int k) {
        bool found = false;
        int val = search(a, b, k, false, found);   // is it in a?
        if (found) return val;
        return search(b, a, k, true, found);       // swap: is it in b?
    }

    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        int lo = kth(a, b, (n + m - 1) / 2);
        int hi = kth(a, b, (n + m) / 2);
        return (lo + hi) / 2.0;
    }
};