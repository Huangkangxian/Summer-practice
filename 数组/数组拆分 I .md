# 题目
给定长度为 2n 的数组, 你的任务是将这些数分成 n 对, 例如 (a1, b1), (a2, b2), ..., (an, bn) ，使得从1 到 n 的 min(ai, bi) 总和最大。
# 链接
https://leetcode-cn.com/problems/array-partition-i

```C
int comp(const void*a,const void*b){
    return *(int*)a-*(int*)b;
}
int arrayPairSum(int* nums, int numsSize){

    int m,sum=0;

    qsort(nums,numsSize,sizeof(int),comp);
    for(m=0;m<numsSize;m+=2){
        sum+=nums[m];
    }
    return sum;
}
```
