#include<stdio.h>
int fun(int a,int b)
{
	int c=10*(a/10)+1000*(a%10)+(b/10)+100*(b%10);
	return c;
}
int main()
{
	int a,b;
	printf("��������λ������a,b");
	scanf("%d %d",&a,&b);
	int c=fun(a,b);
	printf("������Ϊ��%d",c);
	return 0;

}

#include<stdio.h>
void fun(int &a,int &b,int &c)
{
	c=10*(a/10)+1000*(a%10)+(b/10)+100*(b%10);
}
int main()
{
	int a,b;
	printf("��������λ������a,b");
	scanf("%d %d",&a,&b);
	int c;
	fun(a,b,c);
	printf("������Ϊ��%d",c);
	return 0;

}

#include<stdio.h>
int fun(int a,int b,int *c)
{
	*c=10*(a/10)+1000*(a%10)+(b/10)+100*(b%10);
return *c;
}
int main()
{
	int a,b;
	printf("��������λ������a,b");
	scanf("%d %d",&a,&b);
	int *c=fun(a,b);
	printf("������Ϊ��%d",c);
	return 0;

}