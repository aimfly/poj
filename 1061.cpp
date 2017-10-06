#include <iostream>
#include <stdio.h>
using namespace std;

ex_gcd(__int64 a,__int64 b,__int64* x,__int64* y)
{
	__int64 d;
	__int64 t;
	if(0 == b)
	{
		*x=1;
		*y=0;
		return a;
	}
	else
	{
		d=ex_gcd(b,a%b,x,y);
		t = *x;
		*x = *y;
		*y = t-(a/b)*(*y);
		return d;
	}
}


int main(){
	__int64 x,y,m,n,l;
	__int64 d,dx,dy;
	__int64 e;
	__int64 ans;
	scanf("%I64d%I64d%I64d%I64d%I64d",&x,&y,&m,&n,&l);
	d=ex_gcd((m-n),l,&dx,&dy);
	if(((y-x) % d) != 0)
	{
		cout<<"Impossible"<<endl;
		return 0;
	}
	e=dx*((y-x)/d)%l;
	e=e<0?e+l:e;
	d=d<0?-d:d;
	ans=e%(l/d);
	printf("%I64d\n",ans);
	return 0;
}