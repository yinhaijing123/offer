//问题描述： N 个元素，求连续子数组的最大和。 例如：[-1,2,1]，和最大的连续子数组为[2,1]，其和为 3 

//思路如下：定义两个和的变量max_sum、cur_sum分别用来保存：当前连续的序列中最大和是多少，当前连续序列的和；
//          当cur_sum<0时，则说明该序列对整体的和已经没有正向作用，此时令cur_sum=0;继续进行探索。
//          当cur_sum>max_sum时候，令max_sum=cur_sum; 最终得到的max_sum为该序列的连续最大和
#include<iostream>
#include<vector>

using namespace std;

int FindSeqMaxSum(vector<int> array)
{
    if (array.empty())
    {
        return -1;
    }

    int cur_sum = 0;
    int max_sum = array[0];
    for (size_t i = 0; i < array.size(); i++)
    {
        cur_sum += array[i];
        if (cur_sum > max_sum)
        {
            max_sum = cur_sum;
        }

        if (cur_sum < 0)
        {
            cur_sum = 0;
        }
    }
    return max_sum;
}


/**********************************************************************************
                        以下为测试代码
**********************************************************************************/

void TestFindSeqMaxSum()
{
    vector<int> array;
    int n;
    cin >> n;
    for (size_t i = 0; i<n; i++)
    {
        int x;
        cin >> x;
        array.push_back(x);
    }
    int ret = FindSeqMaxSum(array);
    cout << ret << endl;
}

int main()
{
    TestFindSeqMaxSum();
	
	system("pause");
	return 0;
}