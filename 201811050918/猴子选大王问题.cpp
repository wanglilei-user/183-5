#include<stdio.h>
int main()
{
	int m,n,number,count=1;		
	int monkey[999];
	int t;						
	int i;
	printf("��������Ӹ��� m �ͱ��� n ��");
	scanf("%d%d",&m,&n);
	number = m;
	for(i=0;i<m;i++)
		monkey[i]=i+1;
	t=0;
	while(number>1)
	{
		if(monkey[t]>0)
		{
			if(count!=n)
			{
				count++;
				t=(t+1)%m;		
			}
			else
			{
				monkey[t]=0;
				count=1;
				number--;
				t=(t+1)%m;
			}
		}
		else
		{
			t=(t+1)%m;
		}
	}
	for(i=0;i<m;i++)
	{
		if(monkey[i]>0)
			printf("���Ӵ�����%d\n",monkey[i]);
	}
	return 0;
}