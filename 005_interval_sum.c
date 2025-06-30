#include <stdio.h>
#include <stdlib.h>
int intervalSum(int* nums, int numsSize, int intervalStart, int intervalStop);
int main(){
    int num;
    printf("sequence length:");
    scanf("%d", &num);
    int *mm = (int*) malloc(sizeof(int) * num);

    for (int i = 0; i < num; i++)
    {
        scanf("%d", &mm[i]);
    }
    int start, stop;
    printf("start: ");
    scanf("%d", &start);
    printf("stop: ");
    scanf("%d", &stop);
    int result;
    result = intervalSum(mm,num,start,stop);
    printf("%d\n",result);
    system("pause");
    return 0;
}

int intervalSum(int* nums, int numsSize, int intervalStart, int intervalStop) {
    int* presum;
    int postSum;
    presum = (int*) malloc(sizeof(int)*numsSize);
    for(int i=0; i<numsSize; i++){
        if(i==0){
            presum[i] = nums[i];
        } else {
            presum[i] = presum[i-1] + nums[i];
        }
    }
    postSum = presum[intervalStop] - presum[intervalStart-1];
    return postSum;
}