/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* sortedSquaresArray;
    sortedSquaresArray = (int*) malloc(sizeof(int) * numsSize);
    int i=0;
    int j=numsSize-1;
    for(int k=numsSize-1; k>=0; k--){
        if(nums[i]*nums[i] >= nums[j]*nums[j]){
            sortedSquaresArray[k] = nums[i]*nums[i];
            i++;
        } else {
            sortedSquaresArray[k] = nums[j]*nums[j];
            j--;
        }
    }
    *returnSize = numsSize;
    return sortedSquaresArray;
}