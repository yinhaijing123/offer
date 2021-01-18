/*************************************************************************************************************************
问题描述：给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
    说明：
		  初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
		  你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。

思路分析：法1：开辟新空间nums，辅助完成合并。
		  ①分别用两个指针指向nums1和nums2。如果nums1<=nums2,则将nums的数据拷贝至nums；否则，将nums2拷贝至nums，直到num1和num2中有一方遍历到尾部；②若nums1还有剩余未处理数据，则将nums1中剩余数据拷贝至nums；若nums2还有未处理数据，则将nums2中剩余数据拷贝至nums中；③将nums中的数据拷贝至nums1中。
		  法2：将nums2直接合并至nums1，逆序合并。减少移动数据的时间浪费，提高效率。
**************************************************************************************************************************/

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    /*
    //法1：开辟新空间nums，辅助完成合并。
    int *nums3=(int *)malloc(sizeof(int)*(m+n));
    int i=0,j=0,idx=0;

    //比较大小拷贝
    while(i<m && j<n)
    {
        if(nums1[i]<=nums2[j])
        {
            nums3[idx++]=nums1[i++];
        }
        else
            nums3[idx++]=nums2[j++];
    }
    //直接拷贝
    if(i<m)
    {
        memcpy(nums3+idx,nums1+i,sizeof(int)*(m-i));
    }
    if(j<n)
    {
        memcpy(nums3+idx,nums2+j,sizeof(int)*(n-j));
    }
    memcpy(nums1,nums3,sizeof(int)*(n+m));
    
    free(nums3);*/

    //法2：逆序合并
    int end1=m-1;
    int end2=n-1;
    int endnew=m+n-1;

    while(end1>=0&&end2>=0)
    {
        //1.从后向前比较nums1和nums2的数据。如果nums1>=nums2,则将nums1数据放置后面该放的位置；否则，将nums2放入新的位置。
        if(nums1[end1] >= nums2[end2])
        {
            nums1[endnew--]=nums1[end1--];
        }
        else
        {
            nums1[endnew--]=nums2[end2--];
        }
    }
    //若nums2数据遍历完，则得到的即为新数组；若nums1数据遍历完，则将nums2剩余再拷贝至nums1即可。
    while(end2 >=0)
    {
        nums1[endnew--]=nums2[end2--];
    }
}
