#include <iostream>
using namespace std;
#include <cmath>
class CTime
{
	public:
		CTime (int y,int n,int d,int h=0,int m=0,int s=0); //���캯�������β���ΪĬ��ֵ 
		CTime (CTime&t );// �������캯��
		int dayDiff(CTime t);   // ���㵱ǰ�������β� t���ʱ����   �ڶ������  �������β�����Ķ���  �ÿ������캯��
		void showTime();   //��ʾʱ��
		int isvalid();   //�ж����ں�ʱ���Ƿ�Ϸ� 
		~ CTime() {
		           cout<<"��������������"<<endl; 
		          } // ��������
		int cha(int y1,int m1,int d1);  // ����ĳ��ĳ��ĳ������ڹ�Ԫһ���������� 
    private:
	   int year,month,day,hour,minute,second;	 
}; 
   
    CTime::CTime (int y,int n,int d,int h,int m,int s)  //���캯����ʼ����Ա 
    { 
        int flag=1;  //���ô���ʱ��ı�׼ 
	  if(!((y%4==0&&y%100!=0)||y%400==0)&&(n==2))  //��������� 
		{
			if(d>28);
			cout<<"date error!"<<endl;
			flag=0;	
		}
	  else if(n>12)   // һ����� 
	  {
	  	     cout<<"date error!"<<endl;
			flag=0;
	  }
	  else if(n%2==0&&n<8)    // 8��֮ǰ��С�´��� 
	  {
	  	 if(d>30)
	  	 cout<<"date error!"<<endl;
		 flag=0;
	   } 
	   else if(n%2==1&&n>8)   //  8�º��С�´��� 
	   {
	   	if(d>30)
	   	cout<<"date error!"<<endl;
		flag=0;
	   }
	   else if(h>23||m>59||s>59)   // ʱ����� 
	   {
	   	  cout<<"time error!"<<endl;
	   	  flag=0;  
	   }
	   cout<<"���캯��������"<<endl;
	   if(flag==0)    // ����ʱ��
		 year=month=day=hour=minute=second=0;
	   if(flag==1)
    	{
		year=y; month=n;day=d;hour=h;minute=m;second=s;
	    }
	}
	void CTime::showTime()
	{
	   cout<<year<<"/"<<month<<"/"<<day<<" "<<hour<<":" <<minute<<":"<<second<<endl; // ��ʾʱ�� 	    
	}
	int CTime::isvalid()    //  �ж�������ʱ���Ƿ�Ϸ� 
	{
		int flag2;
		if(year==0) 
		flag2=0;
		else
		flag2=1;
		return flag2;
	}
	  CTime::CTime(CTime &t)     //�������캯��ʵ�� 
	  {
	  	year=t.year;month=t.month;day=t.day;   //  t��t2������  ��t2 �ڵ����ڸ��β�t 
	  	cout<<"�������캯��������"<<endl; 
	  }
	  int CTime::cha(int y1,int m1,int d1)   // ������������������ʵ�� 
	  {
	  	int i;
	  	char x[12]={31,28,31,30,31,30,31,31,30,31,30,31};   //  ÿ���µ����� 
	  	int sum=0;
	  	for(i=1;i<y1;i++)
	  	{
	  	  if((i%4==0&&i%100!=0)||i%400==0)	
	  	  sum=sum+366;
		  else
		  sum=sum+365; 
		}
		if((y1%4==0&&y1%100!=0)||y1%400==0)
		{
		x[1]=29;
		}
		for (i=0;i<m1-1;i++) 
		{
			sum=sum+x[i];    //  ���㵱����µ����� 
		}
		sum=sum+d1;   // �����յ�����
		return sum;
	  }
	int CTime::dayDiff(CTime t)    // �����������ڲ�ֵ���� 
	{
	    int n;
	    n=abs(cha(t.year,t.month,t.day )-cha(year,month,day)); // ����t�뵱ǰ����Ƚ� 
		return n;  
	} 
	int  main()
{
        int  year,  month,  day,  hour,  minute,  second;
        cin  >>  year  >>  month  >>  day  >>  hour  >>  minute  >>  second;
        CTime  t1(year,  month,  day,  hour,  minute,  second);
        t1.showTime();
        CTime  t2(2000,  1,  1);  //����Ĭ���βν�ʱ���ʼ��Ϊ00:00:00
        if  (t1.isvalid())          //������ں�ʱ��Ϸ������������
        {
                int  days=0;
                days=t1.dayDiff(t2);
                cout  <<  "������֮�������"  <<  days  <<  "��"  <<  endl;
                days=t2.dayDiff(t1);
                cout  <<  "������֮�������"  <<  days  <<  "��"  <<  endl;
        }
} 
	


