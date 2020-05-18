/*******************************************************************************************
问题描述：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
        例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
        NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

算法思路：旋转排序数组是特殊的排序数组，为提高其效率，可利用二分法进行查找。
        1.定义三个变量index1，indexMid，index2分别为第一个元素下标，中间元素下标，和最后一个元素下标。
        2.特殊情况：当这三个值相等时，无法判断最小值在哪个区间，故只能用顺序查找方法找最小值；
        3.当中间元素值<=最后一个元素值时，表示所求最小值一定在中间元素前面的子数组中；
        4.当中间元素值>=第一个元素时，表示所求最小值一定在中间元素后面的子数组中；
        5.直到index1和index2相邻，则找到最小值。算法复杂度为O(log n)
*******************************************************************************************/
int minNumberInRotateArray(vector<int> rotateArray) {
    if(rotateArray.size()==0)
        return 0;
    int index1=0;
    int indexMid=index1;
    int index2=rotateArray.size()-1;
    while(rotateArray[index1]>=rotateArray[index2])
    {
        if(index2-index1==1)
        {
            indexMid=index2;                   //找到最小值了
            break;
        }  
        indexMid=(index1+index2)/2;
        if(rotateArray[index1]==rotateArray[index2] && rotateArray[index1]==rotateArray[indexMid])
        {
            //顺序查找
            for(int i=index1+1;i<=index2-1;i++)
            {
                if(rotateArray[i]<rotateArray[i+1])
                {
                    return rotateArray[i];
                }
            }
        }
        
        if(rotateArray[indexMid]>=rotateArray[index1]) //前半子数组：为增子数组；后半子数组：为先增后降子数组           
        {
            index1=indexMid;
        }
        else if(rotateArray[indexMid]<=rotateArray[index2])//前半子数组：为先增后降子数组；后半子数组：为增子数组。
        {
            index2=indexMid;
        }
    }
    return rotateArray[indexMid];
}