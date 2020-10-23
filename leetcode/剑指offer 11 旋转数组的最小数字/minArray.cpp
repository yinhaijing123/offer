/*************************************************************************************************************************
问题描述：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。

思路分析：该问题分为两种情况：
		  1.数组中无重复数字（采用二分法）。步骤：if mid<right,说明(mid，right]区间有序，即分界点在[left，mid]区间内；if mid>right,说明[left，mid]区间有序，即分界点在(mid，right]区间内,直到left>=right，得最小值。
		  2.数组中有重复数字（暴力查找）。通过right--来缩小范围。	
**************************************************************************************************************************/

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left=0;
        int right=numbers.size()-1;
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(numbers[mid]<numbers[right])         //说明(mid，right]区间有序，即分界点在[left，mid]区间内.
            {
                right=mid;
            }
            else if(numbers[mid]>numbers[right])    //说明[left，mid]区间有序，即分界点在(mid，right]区间内.
            {
                left=mid+1;
            }
            else 
            {
                right--;
            }
        }
        return numbers[left];
    }
};
