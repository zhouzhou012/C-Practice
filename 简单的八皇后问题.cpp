#include <iostream>
using namespace std;
int main()
{
	int i,i1,m,n;
	int sum=0;
	char s[9];
	int c[7];
	cin.get(s,9);// 输入字符串s[9] 3681*752  1327246*
	for(i=0,i1=0;i<8;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		  { 
		    c[i1]=s[i];
			i1++;
		  }
	    else 
		 m=i+1;//确定未放置棋子的行m=5;c[]存放数字表示已经放置棋子的列   
	 }
		for(i=0;i<7;i++)
			sum=sum+c[i];
	      n=36+336-sum;
	      int find=1;
	      for(i=0;i<7;i++)
		  {
		  if((c[i]-48)==(i+1))// 列数等于行数 
	     {
		  find=0;
		  break;
	     }
	      } 
	      if(find==0&&m==n)
          cout<<"No Answer"<<endl;
          else
          cout<<n;	
          return 0;
}
    
		
	 

