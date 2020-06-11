#include <iostream> 
using namespace std;
int main()
{
	int drink(int i);
	int n;
	cin>>n;
	int d=drink(n)+n;
    cout<<d;   
}
    int a,b;
	int c=0;
	int d=0;
	int sum=0;
   int drink(int i)
   {
	a=i/3;//盖子换的 
	b=i/2;//瓶子换的 
	c+=i%3;  //新盖子累加换剩下的零散盖子 
	d+=i%2;  //新瓶子累加换剩下的零散盖子 
	i=a+b+c/3+d/2;  //一次瓶子和盖子一起换的新水 
	c=c%3; //一次换完后剩下的零散盖子
	d=d%2;//一次换完后剩下的零散盖子
	if(i>0)
	{
		sum+=i;	//sum累加换的总瓶数 
		drink(i);  //函数递归 
	}	
	return sum;
	}

