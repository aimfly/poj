#include<stdio.h>

int get_number(int a)
{
	if(a>=10000 && a<=99999) return 5;
	if(a>=1000 && a<=9999) return 4;
	if(a>=100 && a<=999) return 3;
	if(a>=10 && a<=99) return 2;
	if(a>=1 && a<=9) return 1;
}
int get_out(int num,int n)
{
	int digi[6];
	int i=0;
	while(num)
	{
		digi[i++]=num%10;
		num=num/10;
	}
	return digi[i-n];
}
unsigned int ds[40000][2]; //ds[i][0] save all digital number,ds[i][1] save Si digital number
int main()
{
	int i=0;
	unsigned int in,out;
	int n;
	do{
	  i++;
	  ds[i][1]=ds[i-1][1]+get_number(i);
	  ds[i][0]=ds[i-1][0]+ds[i][1];
  }while(ds[i][0]<2147483647);
  scanf("%d",&n);
  while(n){
  	scanf("%d",&in);
  	for(i=0;ds[i][0]<in;i++);
  	in=in-ds[i-1][0];
  	for(i=0;ds[i][1]<in;i++);
  	out=get_out(i,in-ds[i-1][1]);
  	printf("%d\n",out);
  	n--;
  }
	return 0;
}