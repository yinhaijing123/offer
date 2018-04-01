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
