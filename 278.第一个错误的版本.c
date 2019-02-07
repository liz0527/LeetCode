// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    /*尽量减少调用API次数，使用二分查找。*/
    int low=1,high=n;
    while(low<=high){
        int middle=low + (high-low)/2;
        if(isBadVersion(middle) && !isBadVersion(middle-1)) return middle;
        else {
            if(isBadVersion(middle)){
                high = middle-1;
            }
            else {
                low = middle+1;
            }
        }
    }
    return 0;
}