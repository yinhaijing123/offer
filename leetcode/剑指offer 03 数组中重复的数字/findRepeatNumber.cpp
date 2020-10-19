/*************************************************************************************************************************
问题描述：leetcode 剑指offer 03 : 找出数组中重复的数字。
		  在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

思路分析：方法1：排序。判断相邻数字是否相等。时间复杂度：O(n^2)
		  方法2：由于数字有他们的大小均在0~n-1范围内的特点，故将每一个数值放置到其对应的下标处，如果该下标处已放置对应数据，则说明待放数据为重复数据。时间复杂度：O(n)
**************************************************************************************************************************/


class Solution {
public:
	void sort(vector<int>& nums)
    {
        if(nums.empty())
            return;
        int size=nums.size();
        for(int i=0;i<size-1;i++)
        {
            for(int j=i+1;j<size;j++)
            {
                if(nums[i]>nums[j])
                {
                    int tmp=nums[i];
                    nums[i]=nums[j];
                    nums[j]=tmp;
                }
            }
        }
    }
	int findRepeatNumber1(vector<int>& nums) {
		if(nums.empty())
			return -1;
		int size=nums.size();
		sort(nums);
		for(int i=0;i<size;i++)
		{
			if(nums[i]==nums[i+1])
			{
			   return nums[i];
			}
		}
		return -1;
	}

    int findRepeatNumber2(vector<int>& nums) {
        if(nums.empty())
            return -1;
        int size=nums.size();
        for(int i=0;i<size;i++)
        {
            if(nums[i]==i)
            {
                continue;
            }
            if(nums[nums[i]]==nums[i])
                return nums[i];
            else
            {
                int tmp=nums[nums[i]];
                nums[nums[i]]=nums[i];
                nums[i]=tmp;
            }
        }
        return -1;
    }
}; 