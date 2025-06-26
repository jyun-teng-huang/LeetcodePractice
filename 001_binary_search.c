int search(int* nums, int numsSize, int target) {
    int leftBoundIndice = 0;
    int rightBoundIndice = numsSize-1;
    int middleIndice = (leftBoundIndice+rightBoundIndice)/2;
    // 02345
    while(leftBoundIndice != rightBoundIndice) {
        if(nums[middleIndice] == target) {
            return middleIndice;
        } else if(nums[middleIndice] < target) {
            leftBoundIndice = middleIndice + 1;
            middleIndice = (leftBoundIndice+rightBoundIndice)/2;
        } else {
            rightBoundIndice = middleIndice - 1;
            middleIndice = (leftBoundIndice+rightBoundIndice)/2;
        }
    }
    return -1;
}