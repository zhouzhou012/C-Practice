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
	a=i/3;//���ӻ��� 
	b=i/2;//ƿ�ӻ��� 
	c+=i%3;  //�¸����ۼӻ�ʣ�µ���ɢ���� 
	d+=i%2;  //��ƿ���ۼӻ�ʣ�µ���ɢ���� 
	i=a+b+c/3+d/2;  //һ��ƿ�Ӻ͸���һ�𻻵���ˮ 
	c=c%3; //һ�λ����ʣ�µ���ɢ����
	d=d%2;//һ�λ����ʣ�µ���ɢ����
	if(i>0)
	{
		sum+=i;	//sum�ۼӻ�����ƿ�� 
		drink(i);  //�����ݹ� 
	}	
	return sum;
	}

