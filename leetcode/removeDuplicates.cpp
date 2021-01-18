/*************************************************************************************************************************
问题描述：

思路分析：快慢指针思想。用两个指针分别指向重复数据的头部和尾部。
		  注意：要考虑两种特殊情况：①最后两个元素相同；②最后两个元素不同。
**************************************************************************************************************************/

int removeDuplicates(int* nums, int numsSize){
    if(numsSize<2)
        return numsSize;
    int start=0,end=1,newend=0;
    //
    while(end<numsSize)
    {
        //1.对每个新的元素进行赋值新数组操作
        nums[newend++]=nums[start];
        //2. 当有连续相等的数据时，则需要找到重复数据的尾指针。
        while( end < numsSize &&   nums[start]==nums[end]  )
        {
            end++;
        }
        // if(end < numsSize){
        //3. 找到新元素后，对重复数据标志进行更新
        start=end;
        end++;
        //}
   
    }

    // if(end == numsSize && nums[newend-1] != nums[end-1])
    //    nums[newend++]=nums[start];
    if(start==numsSize-1)
        nums[newend++]=nums[start];
    return newend;
}
