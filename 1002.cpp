#include<iostream>
#include<iomanip>
using namespace std;
int cmp( const void *a , const void *b ) 
{ 
	return *(int *)a - *(int *)b; 
} 
main(){
	int *a,ai;
	int i,n,t,m,tc;
	int ans=0;
	char c[100];
	const int b[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
	cin>>n;
	a=new int[n];
	ai=0;
	m=n;
	while(m--){
		cin>>c;
		t=i=0;
		while(c[i]){
			if(c[i]=='-'){i++;continue;}
			if(c[i]<='Z'&&c[i]>='A')t=t*10+b[c[i]-'A'];
			else t=t*10+c[i]-'0';
			i++;
		}
		a[ai++]=t;
	}
	qsort(a,n,sizeof(int),cmp);
	t=-1;
	tc=0;
	for(i=0;i<n;i++){
		if(a[i]==t)tc++;
		else {
			if(tc>1){
			cout<<setfill('0')<<setw(3)<<t/10000<<"-"<<setfill('0')<<setw(4)<<t%10000<<" "<<tc<<endl;
			ans=1;
			}
			t=a[i];
			tc=1;
		}
	}
	if(tc>1){ans=1;cout<<setfill('0')<<setw(3)<<t/10000<<"-"<<setfill('0')<<setw(4)<<t%10000<<" "<<tc<<endl;}
	if(!ans)cout<<"No duplicates."<<endl;
	return 1;
}