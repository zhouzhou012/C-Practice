#include  <iostream>
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
	Book *m_pBook;  //ָ������new������̬������Book����
	unsigned int m_Count;//��ʾ�����ͼ�������
};
//���ڴ˴�����Store��ĳ�Ա����ʵ��
Store::Store(const Store& other)   //Store �࿽�����캯����ʵ�� 
{
	m_Count=other.m_Count;     //  һ�����ֱ�ӿ��� 
	m_pBook=new Book[m_Count];    //  ��������Ŀ���  �ȴ���������  ����forѭ�� ���� 
	for(int i=0;i<m_Count;i++)
	{
		m_pBook[i]=other.m_pBook[i];
	}       
	cout<<"Store copy constructor called!"<<endl;   
}
void Store::in(Book &b)  /*ע����Ϊ�����һ�����飬������Ҫ����һ���洢�ռ䡣
��ʾ������ͨ��������һ���ռ䣬����ԭ�����ݿ������¿ռ䣬
ͬʱ��������������������һ��Ԫ�أ����ͷ�ԭ�пռ䣬�Ӷ�ʵ�������С�Ķ�̬������*/ 
{ 
	Book* m_pBook1=new Book[m_Count+1];    // ����ͨ��������һ���ռ�
    for(int i=0;i<GetCount();i++)
    {
    	m_pBook1[i]=m_pBook[i];    //ԭ�����ݿ������¿ռ�
	}
	m_pBook1[m_Count]=b;   //ͬʱ��������������������һ��Ԫ��
	delete []m_pBook;  //���ͷ�ԭ�пռ�
	m_pBook=m_pBook1; //ʹָ�� m_pBook�ٴ�ָ���¶�̬���� 
	m_Count=m_Count+1;  //ͼ���������� 
}
void Store::out(string name)  /*ע����Ϊɾ����һ���飬������Ҫ����һ���洢�ռ䡣
��ʾ������ͨ��������һ���ռ䣬����δ��ɾ���Ĳ��ֿ������¿ռ䣬���ͷ�ԭ�пռ䣬�Ӷ�ʵ�������С�Ķ�̬������*/
{
	Book* m_pBook2=new Book[m_Count-1];   //����ͨ��������һ���ռ� 
  for(int i=0,i1=0;i<GetCount();i++)
  {
  	if(m_pBook[i].GetName()!=name)
  	{
  	  m_pBook2[i1]=m_pBook[i];    //����δ��ɾ���Ĳ��ֿ������¿ռ�
		i1++;	
	}
  } 
    delete []m_pBook;    //���ͷ�ԭ�пռ�
	m_pBook=m_pBook2; //ʹָ�� m_pBook�ٴ�ָ���¶�̬���� 
    m_Count=m_Count-1;   //  ͼ���������� 	
} 

Book Store:: findbyID(int ID)   /*Ҫ����ݸ�����ID����ͼ�飬����ҵ����򷵻�һ��Book����Book�����д洢�˶�Ӧ�鱾����Ϣ��
����Ҳ������򷵻�һ��Book����Book�����m_IDΪ0����ʾδ����ʼ����*/ 
{
	int n;
	int find=0;
	Book b4;         //δ��ֵ���� 
	for(int i=0;i<GetCount();i++)   //��ĳ�Ա����GetCount()����ֱ��ʹ��   ��һ���Ƕ���.��Ա���� 
   	{
   	  if(int(m_pBook[i].GetID())== ID)   //ǿ��ת��һ������  �޷���int ==int 
   	  {
		n=i;
   	    find=1;
   	    break;
   	  }
	}
	if(find==0)  //û�ҵ� 
	return b4;    ///����δ��ֵ���� 
	else
	return m_pBook[n];  //�ҵ�  ������Ӧ����  ����ÿ������캯��������ֵ��mian������ ����tmpbook
}
Book Store::findbyName(string name)
{
	int n;
	int find=0;
	Book b5;  //δ��ֵ���� 
	for(int i=0;i<GetCount();i++)
	{
		if(m_pBook[i].GetName()==name)
	    {
	    n=i;
		find=1;
		break;
	   }
	}
	if(find==0)	  //û�ҵ� 
	return b5;     ///����δ��ֵ����     ���߲��ô���b5  д��return   Book() 
	else
	return m_pBook[n];   //�ҵ�  ������Ӧ����  ����ÿ������캯��������ֵ��mian������ ����tmpbook
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
