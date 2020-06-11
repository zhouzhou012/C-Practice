#include  <iostream>
using  namespace  std;
class  Book
{
//请在此处补充Book类的定义
public:
	Book ()       //将m_ID初始化为0，表示这个一个未赋值对象
	{
		m_ID=0;
	}
	virtual ~Book(){}   //无具体的工作
	Book(const Book& other);  //实现所有成员变量的拷贝
	 unsigned int GetID()
	{
		return m_ID;
	}
	void SetID( unsigned int m_ID)
	{
		this->m_ID=m_ID;
	}
	string GetName()
	{
		return m_Name;
	}
	void SetName(string m_Name)
	{
		this->m_Name=m_Name;
	}
	string GetIntroduction()
	{
		return m_Introductio;
	}
	void SetIntroduction(string m_Introductio)
	{
		this->m_Introductio=m_Introductio;
	}
	string GetAuthor()
	{
		return m_Author;
	}
	void SetAuthor(string m_Author)
	{
		this->m_Author=m_Author; 
	}
	string GetDate()
	{
		return m_Date;
	}
	void SetDate(string m_Date)
	{
		this->m_Date=m_Date;
	}
	unsigned int GetPage()
	{
		return m_Page;
	}
	void SetPage(unsigned int m_Page)
	{
		this->m_Page=m_Page; 
	}
private:
    unsigned int m_ID;//编号
    string m_Name;//书名
    string m_Introductio;//简介
    string m_Author;//作者
    string m_Date;//日期
    unsigned int m_Page;//页数
};
//请在此处补充Book类的成员函数实现

Book::Book(const Book& other)
{
	m_ID=other.m_ID;
	m_Name=other.m_Name;
	m_Introductio=other.m_Introductio;
	m_Author=other.m_Author;
	m_Date=other.m_Date;
	m_Page=other.m_Page;	
}
class  Store
{
//请在此处补充Store类的定义
public:
	Store()
	{
		m_Count=0;
		m_pBook=NULL;
		cout<<"Store default constructor called!"<<endl;
	} 
	 Store(int n)
	 {
	 	m_Count=n;
	 	m_pBook=new Book[m_Count];
	 	cout<<"Store constructor with (int n) called!"<<endl;
	 }
	 virtual ~Store()
	 {
	 	m_Count=0;
	 	if(m_pBook!=0)
	 	{
	 		delete[]m_pBook;
	 		cout<<"Store destructor called!"<<endl;
		 }
	 }
	 Store(const Store& other);
	int GetCount()
	{
		return m_Count;
	}
	void SetCount(int m_Count) 
	{
		this->m_Count=m_Count;
	}
	void in(Book &b);
	void out(string name);
	Book findbyID(int ID);
	Book findbyName(string name);
	void printList();
private:
	Book *m_pBook;  //指向利用new操作动态创建的Book数组
	unsigned int m_Count;//表示库存中图书的数量
};
//请在此处补充Store类的成员函数实现
Store::Store(const Store& other)   //Store 类拷贝构造函数的实现 
{
	m_Count=other.m_Count;     //  一般变量直接拷贝 
	m_pBook=new Book[m_Count];    //  对象数组的拷贝  先创建新数组  再用for循环 拷贝 
	for(int i=0;i<m_Count;i++)
	{
		m_pBook[i]=other.m_pBook[i];
	}       
	cout<<"Store copy constructor called!"<<endl;   
}
void Store::in(Book &b)  /*注意因为入库了一本新书，所以需要增加一个存储空间。
提示：可以通过新申请一个空间，并将原有数据拷贝进新空间，
同时将新增的书放在数组最后一个元素，再释放原有空间，从而实现数组大小的动态调整。*/ 
{ 
	Book* m_pBook1=new Book[m_Count+1];    // 可以通过新申请一个空间
    for(int i=0;i<GetCount();i++)
    {
    	m_pBook1[i]=m_pBook[i];    //原有数据拷贝进新空间
	}
	m_pBook1[m_Count]=b;   //同时将新增的书放在数组最后一个元素
	delete []m_pBook;  //再释放原有空间
	m_pBook=m_pBook1; //使指针 m_pBook再次指向新动态数组 
	m_Count=m_Count+1;  //图书数量增加 
}
void Store::out(string name)  /*注意因为删除了一本书，所以需要减少一个存储空间。
提示：可以通过新申请一个空间，并将未被删除的部分拷贝进新空间，再释放原有空间，从而实现数组大小的动态调整。*/
{
	Book* m_pBook2=new Book[m_Count-1];   //可以通过新申请一个空间 
  for(int i=0,i1=0;i<GetCount();i++)
  {
  	if(m_pBook[i].GetName()!=name)
  	{
  	  m_pBook2[i1]=m_pBook[i];    //并将未被删除的部分拷贝进新空间
		i1++;	
	}
  } 
    delete []m_pBook;    //再释放原有空间
	m_pBook=m_pBook2; //使指针 m_pBook再次指向新动态数组 
    m_Count=m_Count-1;   //  图书数量减少 	
} 

Book Store:: findbyID(int ID)   /*要求根据给定的ID查找图书，如果找到，则返回一个Book对象，Book对象中存储了对应书本的信息；
如果找不到，则返回一个Book对象，Book对象的m_ID为0，表示未被初始化。*/ 
{
	int n;
	int find=0;
	Book b4;         //未赋值对象 
	for(int i=0;i<GetCount();i++)   //类的成员函数GetCount()可以直接使用   不一定是对象.成员函数 
   	{
   	  if(int(m_pBook[i].GetID())== ID)   //强制转化一下类型  无符号int ==int 
   	  {
		n=i;
   	    find=1;
   	    break;
   	  }
	}
	if(find==0)  //没找到 
	return b4;    ///返回未赋值对象 
	else
	return m_pBook[n];  //找到  返回相应对象  会调用拷贝构造函数将对象赋值给mian函数的 对象tmpbook
}
Book Store::findbyName(string name)
{
	int n;
	int find=0;
	Book b5;  //未赋值对象 
	for(int i=0;i<GetCount();i++)
	{
		if(m_pBook[i].GetName()==name)
	    {
	    n=i;
		find=1;
		break;
	   }
	}
	if(find==0)	  //没找到 
	return b5;     ///返回未赋值对象     或者不用创建b5  写成return   Book() 
	else
	return m_pBook[n];   //找到  返回相应对象  会调用拷贝构造函数将对象赋值给mian函数的 对象tmpbook
}
void Store:: printList()   
{
	cout<<"There are totally "<<GetCount()<<" Books:"<<endl;
    for(int i=0;i<GetCount();i++)
  	{
	cout<<"ID="<<m_pBook[i].GetID()<<";  ";
	cout<<"Name:"<<m_pBook[i].GetName()<<";  ";
	cout<<"Author:"<<m_pBook[i].GetAuthor()<<";  ";
	cout<<"Date:"<<m_pBook[i].GetDate()<<";  "<<endl;	
     }
 }
int  main()
{
        Store  s;
        Book  b1,b2,b3;
        b1.SetID(1);
        b1.SetName("C++  语言程序设计(第4版)");
        b1.SetAuthor("郑莉");
        b1.SetIntroduction("介绍C++及面向对象的知识");
        b1.SetDate("201007");
        b1.SetPage(529);
        b2.SetID(2);
        b2.SetName("离散数学");
        b2.SetAuthor("左孝凌");
        b2.SetIntroduction("介绍命题逻辑、谓词逻辑、集合论、代数系统和图论");
        b2.SetDate("198209");
        b2.SetPage(305);
        b3.SetID(3);
        b3.SetName("c程序设计");
        b3.SetAuthor("谭浩强");
        b3.SetIntroduction("介绍C程序设计中的基本知识，如语句格式、语法等");
        b3.SetDate("201006");
        b3.SetPage(355);

        cout<<"第一本书入库"<<endl;
        s.in(b1);
        cout<<"第二本书入库"<<endl;
        s.in(b2);
        cout<<"第三本书入库"<<endl;
        s.in(b3);
        cout  <<"现有库存书籍数量："<<s.GetCount()  <<  endl;
        cout  <<"查找并出库图书：离散数学"  <<  endl;
        Book  tmpbook=s.findbyName("离散数学");
        if(tmpbook.GetID()!=0)
        {
                s.out("离散数学");
                cout  <<"离散数学  已成功出库"  <<  endl;
        }
        else
                cout<<"没有找到name为离散数学的书"<<endl;
        cout  <<"现有库存书籍数量："<<s.GetCount()  <<  endl;

        cout  <<"查找图书  ID：3"  <<  endl;
        tmpbook=s.findbyID(3);
        if(tmpbook.GetID()!=0)
                cout<<"找到ID为"<<3<<"的书，书名："<<tmpbook.GetName()<<endl;
        else
                cout<<"没有找到ID为"<<3<<"的书"<<endl;

        cout  <<"查找图书  name：离散数学"  <<  endl;
        tmpbook=s.findbyName("离散数学");
        if(tmpbook.GetID()!=0)
                cout<<"找到name为离散数学的书，ID："<<tmpbook.GetID()<<endl;
        else
                cout<<"没有找到name为离散数学的书"<<endl;

        cout<<"输出所有库存图书的信息"<<endl;
        s.printList();
        cout<<"程序运行结束"<<endl;
        return  0;
}
