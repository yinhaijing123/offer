/**********************************************************************************************************************
问题描述：给定一个数组A[0,1,...,n-1],
          请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。(不能使用除法)
          

思路分析：法一：将B[i]所对应的下标的A数组的值置为1，从而达到整体相乘不改变B[i]值得目的。
                复制一份A[n]数组，作为临时变量，当求解B[i]时，令T[i]=1，求叠乘，求完之后再恢复该值。
                其时间复杂度为O(n^2)

          法二：可将B[i]=C[i]*D[i]，其中C[i]=A[0]A[1]*...*A[i-1]=C[i-1]*A[i-1]， D[i]=A[i+1]*A[i+2]*...A[n-1]=A[i+1]*D[i+1]
          (以空间换时间，提高效率。时间复杂度为O(n))
**********************************************************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

//法一实现：

//vector<int> multiply(const vector<int>& A) 
//{
//    vector<int> B;
//    vector<int> T(A);
//    
//    for (size_t i = 0; i < T.size(); i++)
//    {
//        int multi = 1;
//        int tmp = T[i];
//        T[i] = 1;
//        for (size_t j = 0; j < T.size(); j++)
//        {
//            multi *= T[j];
//        }
//        B.push_back(multi);
//        T[i] = tmp;
//    }
//    return B;
//}


//法二实现：

vector<int> multiply(const vector<int>& A) 
{
    int size = A.size();
    vector<int> B(size);
    vector<int> C(size);
    vector<int> D(size);

    size_t i = 0;
    C[0] = 1;
    for (i=1; i < size; i++)
    {
        C[i] = C[i - 1] * A[i - 1];
    }

    D[size - 1] = 1;
    for (i = size-1; i > 0; i--)
    {
        D[i-1] = D[i] * A[i];
    }

    for (i = 0; i < size; i++)
    {
        B[i] = C[i] * D[i];
    }

    return B;
}

//////////////////////////////////以下进行简单测试////////////////////////////////
{
    vector <int>A;
    for (size_t i = 1; i < 6; i++)
    {
        A.push_back(i);
    }
    for (size_t i = 0; i < A.size(); i++)
    {
        cout << A[i] << ' ';
    }
    cout << endl;

    vector<int> B = multiply(A);
    for (size_t i = 0; i < B.size(); i++)
    {
        cout << B[i] << ' ';
    }
    cout << endl;
}

int main()
{
    Test();

	system("pause");
	return 0;
}