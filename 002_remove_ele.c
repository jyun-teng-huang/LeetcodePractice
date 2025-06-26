int removeElement(int* nums, int numsSize, int val) {
    int fastIndice = 0;
    int slowIndice = 0;
    for(fastIndice=0; fastIndice<numsSize; fastIndice++){
        nums[slowIndice] = nums[fastIndice];
        if(nums[slowIndice]==val){
            slowIndice = slowIndice;
        } else {
            slowIndice ++;
        }
    }
    return slowIndice;
}