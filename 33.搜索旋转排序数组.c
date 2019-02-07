int search(int* nums, int numsSize, int target) {
    /*先找到旋转点。再进行二分查找。*/
    int low=0,high=numsSize-1;
    int spin=0;
    /*如果一个数比它后面的数大，那么后一个数就是旋转的地方。*/
    for(int i=0;i<numsSize;i++){
        if(nums[i]>nums[i+1]) {
            spin = i;
            /*先看target在前半部分还是后半部分*/
            if(target<nums[0]){
                low = spin+1;
            }
            else {
                high = spin;
            }
            break;
        }
    }
    /*二分查找*/
    while(low<=high){
        int middle=low+(high-low)/2;
        if(target==nums[middle]) return middle;
        else {
            if(target<nums[middle]){
                high = middle-1;
            }
            else {
                low = middle+1;
            }
        }
    }
    return -1;
}