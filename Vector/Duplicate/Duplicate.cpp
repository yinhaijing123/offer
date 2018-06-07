/*************************************************************************************************************************
问题描述：数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 
          例如，如果输入长度为7的数组{ 2,3,1,0,2,5,3 }，那么对应的输出是第一个重复的数字2。

思路分析：查找数组元素问题，一般可使用哈希表实现。
**************************************************************************************************************************/
#include<iostream>
#include<vector>

using namespace std;

bool duplicate(int numbers[], int length, int* duplication) 
{
    vector<int> hash_table;
    hash_table.resize(length,0);

    for (size_t i = 0; i < length; i++)                             //遍历数组，并插入哈希表中
    {
        hash_table[numbers[i]] += 1;
    }

    for (size_t i = 0; i < length; i++)                             //找重复数字
    {
        if (hash_table[numbers[i]] > 1)
        {
            duplication[hash_table[numbers[i]] = numbers[i];
            return true;
        }
    }
    return false;
} 