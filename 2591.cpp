#include <iostream.h>
long result[10000000];
int main(){
	long t1,t2;
	long x2,x3;
	long a;
	int n=0;
	x2=x3=0;
	result[0]=1;
	while(n<10000000){
		t1=result[x2]*2+1;
		t2=result[x3]*3+1;
		if(t1<=t2)
			{if(t1!=result[n]){result[++n]=t1;x2++;}
			else x2++;}
		else if(t2!=result[n]){result[++n]=t2;x3++;}
			else x3++;
	}
	while(cin>>a)cout<<result[a-1]<<endl;
	return 0;
}