#include<iostream> 
#include<string.h>

using namespace std; 

class CMyString{
public:
    CMyString(char *pData=nullptr)
    {
        cout<<"CMyString()"<<endl;
        m_pData =new char[strlen(pData)+1];
        strcpy(this->m_pData,pData);
    }
	
    CMyString(const CMyString &str)
    {
        cout<<"CMyString Copy"<<endl;
        m_pData =new char[strlen(str.m_pData)+1];
        strcpy(this->m_pData,str.m_pData);
    }
	//法1：实现需考虑四方面：1.返回值（为连续赋值，返回值类型为类名的引用）；2.参数（提高效率，参数传引用类型，避免不必要的拷贝开销，同时参数声明为常量引用，即const，避免复制时误改参数值）；3.对象自己给自己赋值情况（特殊情况，特殊处理直接返回*this）；4.释放之前空间后，再进行赋值（避免内存泄漏）。
    CMyString& operator=(const CMyString &str)
    {
        cout<<"operator="<<endl;
        if(this==&str)
        {
            return *this;
        }
        delete []m_pData;
        m_pData=nullptr;

        m_pData=new char[strlen(str.m_pData)+1];
        strcpy(m_pData,str.m_pData);
        return *this;
    }
	//法2：对法1的优化。利用局部变量出作用域会自动调用析构函数思想，调用拷贝构造函数创建局部变量，将被赋值数所指向的空间与局部变量进行交换，让系统进行自动释放。
	/*CMyString& MyString::operator=(const CMyString& str)
	{
		if (this != &str)
		{
			MyString tmp(str);
			swap(tmp.m_pData, m_pData);
		}
		return *this;
	}*/
    //法3：对法2的优化。直接利用传参时调用拷贝构造函数构造临时的str，交换两者。
	/*CMyString& MyString::operator=(CMyString str)
	{
		swap(str.m_pData, m_pData);
		return *this;
	}*/
    void Show()
    {
        cout<<m_pData<<endl;
    }
	
    ~CMyString()
    {
        cout<<"~CMyString()"<<endl;
        free(this);
    }
	
    private:
    char *m_pData;
};

/////////////////////////////////////////////////////////////////////////////////////////////////
                                       以下为测试代码
/////////////////////////////////////////////////////////////////////////////////////////////////

void Test1()                           //1.用一个对象去赋值给另一个对象
{
	char a[10]="abcde";
	char b[]="hello";

    CMyString str(a);
	CMyString str2(b);
	
	str2=str;
	printf("The expected result is %s\n",a);
	printf("The actual result is");
	str2.Show();
	
}

void Test2()                           //2.某对象赋值给自己
{	char a[10]="abcde";

    CMyString str(a);
	str=str;
	
	printf("The expected result is %s\n",a);
	printf("The actual result is");
	str.Show();
	
}

void Test3()                           //3.连续赋值
{
	char a[10]="abcde";
	char b[]="world";
	char c[]="hallo";
	
	CMyString str1(a);
    CMyString str2(b);
    CMyString str3(c);
	str3=str2=str1;
	
	printf("The expected result is %s\n",a);
	printf("The actual result is");
	str2.Show();
	
	printf("The expected result is %s\n",a);
	printf("The actual result is");
	str3.Show(); 
}
int main()
{
   Test1();
   Test2();
   Test3();
   
   return 0;
}
