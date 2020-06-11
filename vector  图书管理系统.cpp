#include  <iostream>
#include <vector>
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
	void SetID(unsigned int m_ID)
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
		cout<<"Store default constructor called!"<<endl;
	} 
	 Store(int n)    //本题是没有调用该构造函数 
	 {
	 	m_Count=n;
	 	vector<Book> m_books(m_Count);
	 	cout<<"Store constructor with (int n) called!"<<endl;
	 }
	 virtual ~Store()
	 {
	 		cout<<"Store destructor called!"<<endl;
	 }
	 Store(const Store& other);
	unsigned int GetCount()
	{
		return m_Count;
	}
	void in(Book &b);
	void out(string name);
	Book findbyID(int ID);
	Book findbyName(string name);
	void printList();
private:
	 unsigned int m_Count;//表示库存中图书的数量
	 vector<Book>m_books;  //  定义m_books   默认初始化 为空  还没有分配内存空间 程序中会根据需要动态添加 或减小 
	
};
//请在此处补充Store类的成员函数实现
Store::Store(const Store& other)/*实现对象数组的拷贝，并输出"Store copy constructor called!";
	                             vector已经解决了深拷贝的问题，这里无需做深拷贝设计。*/ 
{
	this->m_books=m_books; // 拷贝 
	cout<<"Store copy constructor called!"<<endl;
	
}
void Store::in(Book &b)
{    
     m_books.push_back(b);    //利用vector的成员函数可以直接实现添加元素功能  数组大小动态加一 
	 m_Count++;      
}
void Store::out(string name)
{
	vector<Book>::iterator m;   ////使用迭代器 访问数组元素 
	for (m=m_books.begin();m!=m_books.end();m++) 
       {
	   if((*m).GetName()==name) 
	   { 
	       m_books.erase(m);  //利用vector的成员函数可以直接实现删除元素功能   数组大小动态减一 
	   }
      }
    m_Count--;
}
Book Store:: findbyID(int ID)  //使用迭代器 访问数组元素 
{	
    int find=0;
    Book b4;   //未赋值对象 
    Book b;
	vector<Book>::iterator m;
  for (m=m_books.begin();m!=m_books.end();m++) 
       {
	   if((*m).GetID()==ID) 
	   { 
	       find=1;
	       b=*m;     //拷贝对象 
	       break;
	   }
      }
	   if(find==0)
	   return b4;
	   else
	   return b;
}
Book Store::findbyName(string name)   
{
	int find=0;
	Book b5;   //未赋值对象 
	Book b;
	vector<Book>::iterator m;
	for (m=m_books.begin();m!=m_books.end();m++) 
       {
	   if((*m).GetName()==name) 
	   { 
	       find=1;
	       b=*m;   //拷贝对象 
	       break;
	   }
      }
	if(find==0)	
	return b5;
	else
	return b;	
}
void Store:: printList()   
{
	cout<<"There are totally "<<GetCount()<<" Books:"<<endl;
  for(unsigned int i=0;i<GetCount();i++)
  {	cout<<"ID="<<m_books[i].GetID()<<";  ";
  cout<<"Name:"<<m_books[i].GetName()<<";  ";
  cout<<"Author:"<<m_books[i].GetAuthor()<<";  ";
  cout<<"Date:"<<m_books[i].GetDate()<<";  "<<endl;	
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
