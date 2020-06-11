#include  <iostream>
#include <vector>
using  namespace  std;
class  Book
{
//���ڴ˴�����Book��Ķ���
public:
	Book ()       //��m_ID��ʼ��Ϊ0����ʾ���һ��δ��ֵ����
	{
		m_ID=0;
	}
	virtual ~Book(){}   //�޾���Ĺ���
	Book(const Book& other);  //ʵ�����г�Ա�����Ŀ���
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
	unsigned int m_ID;//���
    string m_Name;//����
    string m_Introductio;//���
    string m_Author;//����
    string m_Date;//����
    unsigned int m_Page;//ҳ��
};
//���ڴ˴�����Book��ĳ�Ա����ʵ��

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
//���ڴ˴�����Store��Ķ���
public:
	Store()
	{
		m_Count=0;
		cout<<"Store default constructor called!"<<endl;
	} 
	 Store(int n)    //������û�е��øù��캯�� 
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
	 unsigned int m_Count;//��ʾ�����ͼ�������
	 vector<Book>m_books;  //  ����m_books   Ĭ�ϳ�ʼ�� Ϊ��  ��û�з����ڴ�ռ� �����л������Ҫ��̬��� ���С 
	
};
//���ڴ˴�����Store��ĳ�Ա����ʵ��
Store::Store(const Store& other)/*ʵ�ֶ�������Ŀ����������"Store copy constructor called!";
	                             vector�Ѿ��������������⣬���������������ơ�*/ 
{
	this->m_books=m_books; // ���� 
	cout<<"Store copy constructor called!"<<endl;
	
}
void Store::in(Book &b)
{    
     m_books.push_back(b);    //����vector�ĳ�Ա��������ֱ��ʵ�����Ԫ�ع���  �����С��̬��һ 
	 m_Count++;      
}
void Store::out(string name)
{
	vector<Book>::iterator m;   ////ʹ�õ����� ��������Ԫ�� 
	for (m=m_books.begin();m!=m_books.end();m++) 
       {
	   if((*m).GetName()==name) 
	   { 
	       m_books.erase(m);  //����vector�ĳ�Ա��������ֱ��ʵ��ɾ��Ԫ�ع���   �����С��̬��һ 
	   }
      }
    m_Count--;
}
Book Store:: findbyID(int ID)  //ʹ�õ����� ��������Ԫ�� 
{	
    int find=0;
    Book b4;   //δ��ֵ���� 
    Book b;
	vector<Book>::iterator m;
  for (m=m_books.begin();m!=m_books.end();m++) 
       {
	   if((*m).GetID()==ID) 
	   { 
	       find=1;
	       b=*m;     //�������� 
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
	Book b5;   //δ��ֵ���� 
	Book b;
	vector<Book>::iterator m;
	for (m=m_books.begin();m!=m_books.end();m++) 
       {
	   if((*m).GetName()==name) 
	   { 
	       find=1;
	       b=*m;   //�������� 
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
        b1.SetName("C++  ���Գ������(��4��)");
        b1.SetAuthor("֣��");
        b1.SetIntroduction("����C++����������֪ʶ");
        b1.SetDate("201007");
        b1.SetPage(529);
        b2.SetID(2);
        b2.SetName("��ɢ��ѧ");
        b2.SetAuthor("��Т��");
        b2.SetIntroduction("���������߼���ν���߼��������ۡ�����ϵͳ��ͼ��");
        b2.SetDate("198209");
        b2.SetPage(305);
        b3.SetID(3);
        b3.SetName("c�������");
        b3.SetAuthor("̷��ǿ");
        b3.SetIntroduction("����C��������еĻ���֪ʶ��������ʽ���﷨��");
        b3.SetDate("201006");
        b3.SetPage(355);

        cout<<"��һ�������"<<endl;
        s.in(b1);
        cout<<"�ڶ��������"<<endl;
        s.in(b2);
        cout<<"�����������"<<endl;
        s.in(b3);
        cout  <<"���п���鼮������"<<s.GetCount()  <<  endl;
        cout  <<"���Ҳ�����ͼ�飺��ɢ��ѧ"  <<  endl;
        Book  tmpbook=s.findbyName("��ɢ��ѧ");
        if(tmpbook.GetID()!=0)
        {
                s.out("��ɢ��ѧ");
                cout  <<"��ɢ��ѧ  �ѳɹ�����"  <<  endl;
        }
        else
                cout<<"û���ҵ�nameΪ��ɢ��ѧ����"<<endl;
        cout  <<"���п���鼮������"<<s.GetCount()  <<  endl;

        cout  <<"����ͼ��  ID��3"  <<  endl;
        tmpbook=s.findbyID(3);
        if(tmpbook.GetID()!=0)
                cout<<"�ҵ�IDΪ"<<3<<"���飬������"<<tmpbook.GetName()<<endl;
        else
                cout<<"û���ҵ�IDΪ"<<3<<"����"<<endl;

        cout  <<"����ͼ��  name����ɢ��ѧ"  <<  endl;
        tmpbook=s.findbyName("��ɢ��ѧ");
        if(tmpbook.GetID()!=0)
                cout<<"�ҵ�nameΪ��ɢ��ѧ���飬ID��"<<tmpbook.GetID()<<endl;
        else
                cout<<"û���ҵ�nameΪ��ɢ��ѧ����"<<endl;

        cout<<"������п��ͼ�����Ϣ"<<endl;
        s.printList();
        cout<<"�������н���"<<endl;
        return  0;
}
