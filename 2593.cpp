#include<iostream>
using namespace std;
int num[100000];
int a[100000];
int b[100000];
int main(){
	int n;
	int i;
	int t1,t2,maxa,maxb,max;
	cin>>n;
	while(n){
		i=0;
		memset(num,0,400000);
		memset(a,0,400000);
		memset(b,0,400000);
		while(i<n)cin>>num[i++];
		t1=t2=-1000;
		max=maxa=maxb=-1000;
		for(i=0;i<n;i++){
			if(t1<0)t1=num[i];
			else t1+=num[i];
			if(t1>maxa)maxa=t1;
			a[i]=maxa;
			if(t2<0)t2=num[n-i-1];
			else t2+=num[n-i-1];
			if(t2>maxb)maxb=t2;
			b[n-i-1]=maxb;
		}
		for(i=0;i<n-1;i++)if(a[i]+b[i+1]>max)max=a[i]+b[i+1];
		cout<<max<<endl;
		cin>>n;
	}
	return 0;
}