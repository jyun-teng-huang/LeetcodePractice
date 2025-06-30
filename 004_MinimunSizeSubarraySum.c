int minSubArrayLen(int target, int* nums, int numsSize) {
    int subarrayStartPoint = 0;
    int subarrayStopPoint = 0;
    int subarraySum = 0;
    int subarrayLength=0;
    for(subarrayStopPoint; subarrayStopPoint<numsSize; subarrayStopPoint++){
        subarraySum += nums[subarrayStopPoint];
        while(subarraySum >= target){
            subarrayLength = subarrayStopPoint-subarrayStartPoint+1;
            subarraySum -= nums[subarrayStartPoint];
            subarrayStartPoint ++;
        }
    }
    return subarrayLength;
}