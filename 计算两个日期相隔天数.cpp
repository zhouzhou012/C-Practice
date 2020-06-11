#include <iostream>
using namespace std;
#include <cmath>
class CTime
{
	public:
		CTime (int y,int n,int d,int h=0,int m=0,int s=0); //构造函数部分形参设为默认值 
		CTime (CTime&t );// 拷贝构造函数
		int dayDiff(CTime t);   // 计算当前对象与形参 t相隔时天数   第二种情况  函数的形参是类的对象  用拷贝构造函数
		void showTime();   //显示时间
		int isvalid();   //判断日期和时间是否合法 
		~ CTime() {
		           cout<<"析构函数被调用"<<endl; 
		          } // 析构函数
		int cha(int y1,int m1,int d1);  // 计算某年某月某日相对于公元一年的相差天数 
    private:
	   int year,month,day,hour,minute,second;	 
}; 
   
    CTime::CTime (int y,int n,int d,int h,int m,int s)  //构造函数初始化成员 
    { 
        int flag=1;  //重置错误时间的标准 
	  if(!((y%4==0&&y%100!=0)||y%400==0)&&(n==2))  //非闰年情况 
		{
			if(d>28);
			cout<<"date error!"<<endl;
			flag=0;	
		}
	  else if(n>12)   // 一般错误 
	  {
	  	     cout<<"date error!"<<endl;
			flag=0;
	  }
	  else if(n%2==0&&n<8)    // 8月之前的小月错误 
	  {
	  	 if(d>30)
	  	 cout<<"date error!"<<endl;
		 flag=0;
	   } 
	   else if(n%2==1&&n>8)   //  8月后的小月错误 
	   {
	   	if(d>30)
	   	cout<<"date error!"<<endl;
		flag=0;
	   }
	   else if(h>23||m>59||s>59)   // 时间错误 
	   {
	   	  cout<<"time error!"<<endl;
	   	  flag=0;  
	   }
	   cout<<"构造函数被调用"<<endl;
	   if(flag==0)    // 重置时间
		 year=month=day=hour=minute=second=0;
	   if(flag==1)
    	{
		year=y; month=n;day=d;hour=h;minute=m;second=s;
	    }
	}
	void CTime::showTime()
	{
	   cout<<year<<"/"<<month<<"/"<<day<<" "<<hour<<":" <<minute<<":"<<second<<endl; // 显示时间 	    
	}
	int CTime::isvalid()    //  判断日期与时间是否合法 
	{
		int flag2;
		if(year==0) 
		flag2=0;
		else
		flag2=1;
		return flag2;
	}
	  CTime::CTime(CTime &t)     //拷贝构造函数实现 
	  {
	  	year=t.year;month=t.month;day=t.day;   //  t是t2的引用  将t2 内的日期给形参t 
	  	cout<<"拷贝构造函数被调用"<<endl; 
	  }
	  int CTime::cha(int y1,int m1,int d1)   // 单独计算天数函数的实现 
	  {
	  	int i;
	  	char x[12]={31,28,31,30,31,30,31,31,30,31,30,31};   //  每个月的天数 
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
			sum=sum+x[i];    //  计算当年的月的天数 
		}
		sum=sum+d1;   // 计算日的天数
		return sum;
	  }
	int CTime::dayDiff(CTime t)    // 计算两个日期差值天数 
	{
	    int n;
	    n=abs(cha(t.year,t.month,t.day )-cha(year,month,day)); // 参数t与当前对象比较 
		return n;  
	} 
	int  main()
{
        int  year,  month,  day,  hour,  minute,  second;
        cin  >>  year  >>  month  >>  day  >>  hour  >>  minute  >>  second;
        CTime  t1(year,  month,  day,  hour,  minute,  second);
        t1.showTime();
        CTime  t2(2000,  1,  1);  //利用默认形参将时间初始化为00:00:00
        if  (t1.isvalid())          //如果日期和时间合法，则计算天数
        {
                int  days=0;
                days=t1.dayDiff(t2);
                cout  <<  "这两天之间相隔了"  <<  days  <<  "天"  <<  endl;
                days=t2.dayDiff(t1);
                cout  <<  "这两天之间相隔了"  <<  days  <<  "天"  <<  endl;
        }
} 
	


