/*************************************************************************************************************************
问题描述：洗牌在生活中十分常见，现在需要写一个程序模拟洗牌的过程。 现在需要洗2n张牌，从上到下依次是第1张，第2张，第3张一直到第2n张。
		  首先，我们把这2n张牌分成两堆，左手拿着第1张到第n张（上半堆），右手拿着第n+1张到第2n张（下半堆）。
		  接着就开始洗牌的过程，先放下右手的最后一张牌，再放下左手的最后一张牌，接着放下右手的倒数第二张牌，再放下左手的倒数第二张牌，直到最后放下左手的第一张牌。
		  接着把牌合并起来就可以了。 例如有6张牌，最开始牌的序列是1,2,3,4,5,6。首先分成两组，左手拿着1,2,3；右手拿着4,5,6。
		  在洗牌过程中按顺序放下了6,3,5,2,4,1。把这六张牌再次合成一组牌之后，我们按照从上往下的顺序看这组牌，就变成了序列1,4,2,5,3,6。 
		  现在给出一个原始牌组，请输出这副牌洗牌k次之后从上往下的序列。
		  示例：
		  输入：
				3                      ——3组数据
				3 1                    ——第1组数据个数为2*3=6个，对该组数据实行一次操作
				1 2 3 4 5 6            ——第1组数据
				3 2                    ——第2组数据个数为2*3=6个，对该组数据实行两次操作
				1 2 3 4 5 6            ——第2组数据
				2 2                    ——第3组数据个数为2*2=4个，对该组数据实行两次操作
				1 1 1 1                ——第3组数据
	  	  输出：
				1 4 2 5 3 6
				1 5 4 3 2 6
				1 1 1 1
			
思路分析：解法1：暴力解法
          1.数据分为两组，g1为data[0，n-1]；g2为data[n,2n-1]————其中:n=data.size()/2。
		  2.令i=n-1，依次从后向前先g2再g1将g2、g1元素插入ret数组（保存最后结果），再对ret进行翻转操作，即得到一次操作结果，循环k次即可。
		  
		  解法2：找出变化前数组中元素下标和变化后数组元素下标存在的关系
				 每操作一次,数组元素的下标（对于操作前的元素下标）的变化有此规律:
					 ① data数组前半部分数据，即index<size/2，有index=index*2；
					 ② 而data数组后半部分，即size/2<=index<size，有index=2*(index-size/2)+1.
		  步骤：
		  1. 计算经历times次之后，下标为i的元素经历k次操作之后的下标index
		  2. 将下标为i的数据存入待返回序列中的index位置。
		  3. 循环1~2,操作，直到遍历完整个data数组。
牛客链接：https://www.nowcoder.com/questionTerminal/5a0a2c7e431e4fbbbb1ff32ac6e8dfa0
**************************************************************************************************************************/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//法1：暴力解法
vector<int> HandlerData1(const vector<int>& data,int k)
{
    //1.数据分为两组，g1为data[0，n-1]；g2为data[n,2n-1]————其中:n=data.size()/2。
    //2.令i=n-1，依次从后向前先g2再g1将g2、g1元素插入ret数组（保存最后结果），再对ret进行翻转操作，即得到一次操作结果，循环k次即可。
    vector<int> ret(data.begin(),data.end());
    while(k--)
    {
        int n=data.size()/2;
        vector<int> g1(ret.begin(),ret.begin()+n);
        vector<int> g2(ret.begin()+n,ret.end());
        ret.clear();
        for(int i=n-1;i>=0;--i)
        {
            ret.push_back(g2[i]);
            ret.push_back(g1[i]);
        }
        reverse(ret.begin(),ret.end());
    }
    
    return ret;
}

//法2：
vector<int> HandlerData(const vector<int>& data,int k)
{
    //每操作一次,数组元素的下标（对于操作前的元素下标）的变化有此规律:data数组前半部分数据，即index<size/2，有index=index*2；而data数组后半部分，即size/2<=index<size，有index=2*(index-size/2)+1.
    int size=data.size();
	vector<int> ret(size);
    for(int i=0;i<size;++i)
    {
        //计算经历times次之后，下标为i的元素的下标变为哪个下标
        int times=k;
        int n=size/2;
        int index=i;
        while(times--)
        {
            if(index<n)
                index=2*index;
            else
                index=2*(index-n)+1;
        }
        //此时的index即为i经过k次变化之后的新下标
        ret[index]=data[i]; //将该数据存入待返回序列中的合适位置中。
    }
    
	return ret;
}
int main()
{
    int group;
    int n,k;
    cin>>group;            //group：共有多少组数据要操作
    while(group--)
    {
        cin>>n>>k;         //2n：待操作数据个数，k：待操作次数
        int elenum=2*n;
        vector<int> data;
        while(elenum--)
        {
            int x;
            cin>>x;
            data.push_back(x);
        }
        vector<int> ret = HandlerData(data,k);
        
        //打印结果
        for(int i=0;i<2*n;++i)
        {
            cout<<ret[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}