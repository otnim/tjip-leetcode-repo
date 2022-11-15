//TC: O(logn)
//MC: O(1)

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1, hi = n, firstBad;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(isBadVersion(mid)){
                firstBad = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return firstBad;
    }
};


// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
