
//在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
//完成一个函数，要求：输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。其时间复杂度< O(n^2)

//分析如下：
//这个二维数组的特点是：右上角的元素的左侧元素始终大于该行元素并且小于该列元素。根据这个特点，可每次排除一行或者一列。

#include<iostream>
#include<vector>

using namespace std;


bool Find(int target, vector<vector<int> > array) {
    if (array.size() != 0)
    {
        size_t col = array[0].size();
        size_t row = array.size();
        int i = 0;

        int j = col - 1; 
        while (j >= 0 && i <= row - 1)
        {
            if (array[i][j] == target)
            {
                return true;
            }
            else if (array[i][j] > target)                   //被找元素若小于当前元素，则当前元素所在列肯定均大于待查找元素，故，排除了该列。
            {
                j--;
            }

            else
            {
                i++;
            }
        }

    }
    

    return false;
}

/***************************************************
			     测试代码如下
***************************************************/
void Test()
{
    vector<vector<int>> array1;                                         //空数组
    cout << "expect is 0,actual " << Find(0, array1)<<endl;


    vector<vector<int> > array2(3, vector<int>(4));                     //3*4二维数组，默认值为0

    cout <<"expect is 1,actual "<< Find(0, array2) <<endl;
    cout <<"expect is 0,actual " << Find(1, array2) <<endl;

    vector<vector<int>> array3;                                         //3*3二维数组，其元素为第一行的三个元素都为0，第二行的三个元素都为1，第三行的三个元素都为2。
    for (size_t i = 0; i<3; i++)
    {
        array3.push_back(vector<int>(3,i));
    }

    cout <<"expect is 1,actual "<< Find(2, array3) << endl;
    cout <<"expect is 0,actual " << Find(3, array3) << endl;
}

int main()
{
    Test();
    
    system("pause");
    return 0;
}