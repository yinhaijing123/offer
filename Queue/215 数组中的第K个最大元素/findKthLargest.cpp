/*************************************************************************************************************************
问题描述：在未排序的数组中找到第 k 个最大的元素。
		  请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素

思路分析：方法1：排序（从大到小的顺序排序），返回第k-1个下标的元素——但库中sort默认排序方式为正序（即从小到大），即返回下标为size-k的元素。（时间复杂度：快排—O(nlogn),空间复杂度：O(1)）
		  方法2：建小堆，用vector构造小堆，之后将小堆出堆，直到剩K个元素，返回堆顶元素。（时间复杂度：O(nlogn),空间复杂度：O(logn)）
		  方法3：建容量为k的小堆，遍历nums插入小堆中，如果小堆已满，则判断要入堆的元素和堆顶元素的大小关系。若待入堆元素的值大于堆顶元素，则出堆顶元素，入新值，否则，遍历下一个元素。（时间复杂度：O(nlogk),空间复杂度：O(logk)）
		  方法4：使用快速选择算法实现
		  
**************************************************************************************************************************/

class Solution {
public:
    //方法1:排序（从大到小的顺序排序），返回第k-1个下标的元素——但库中sort默认排序方式为正序（即从小到大），即返回下标为size-k的元素。
    int findKthLargest1(vector<int>& nums, int k) {
        int size=nums.size();
        sort(nums.begin(),nums.end());
        return nums[size-k];
    }

    //方法2：建小堆，用vector构造小堆，之后将小堆出堆，直到剩K个元素，返回堆顶元素
    int findKthLargest2(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> Kval(nums.begin(),nums.end());
        while(Kval.size()!=k)
        {
            Kval.pop();
        }
        return Kval.top();
    }
	//方法3：建容量为k的小堆，遍历nums插入小堆中，如果小堆已满，则判断要入堆的元素和堆顶元素的大小关系。若待入堆元素的值大于堆顶元素，则出堆顶元素，入新值，否则，遍历下一个元素。
	int findKthLargest3(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> Kval;
        for(auto e:nums)
        {
            if(Kval.size()==k)
            {
                if(e < Kval.top())
                    continue;
                else
                    Kval.pop();
            }

            Kval.push(e);
        }
        return Kval.top();
    }
	
	//方法4：使用快速选择算法实现
	void swap(int &a,int &b)
	{
		int tmp=a;
		a=b;
		b=tmp;
	}
	int partion(vector<int> &nums,int left,int right)
	{
		 //1. 取基准值,保存其初始所在下标
		int Keyindex=rand() % (right-left+1) + left;
		swap(nums[Keyindex],nums[left]);
		Keyindex=left;

		while(left<right)
		{
			//从右向左找小于基准值
			while(left<right && nums[right]>=nums[Keyindex])
				right--;
			//从左向右找大于基准值的
			while(left<right && nums[left]<nums[Keyindex])
				left++;
			//交换
			swap(nums[right],nums[left]);
			
		}
		
		//交换相遇点与基准值位置
		swap(nums[right],nums[Keyindex]);
		return Keyindex;
	}
	int quickSelect(vector<int> &nums,int left,int right,const int& k)
	{     
		//1. 将小于基准值的元素放在基准值左侧，大于等于基准值的放在基准值右侧。
		int pos=partion(nums,left,right);
		//2. 判断基准值所在位置下标与k的下标是否相等，若相等。返回基准值；若基准值所在下标小于k，则left=基准值下标+1，继续递归;若基准值所在下标大于k，则right=基准值下标-1，递归继续实现。
		
		if(pos==k) 
			return nums[pos];
		else{
			return pos>k?quickSelect(nums,left,pos-1,k):quickSelect(nums,pos+1,right,k);
		}               
	}

	//快速选择
	int findKthLargest(vector<int>& nums, int k) {
		return quickSelect(nums,0,nums.size()-1,nums.size()-k);
	}
};

