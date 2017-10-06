#include<iostream>
using namespace std;
long a[201][2];
int main(){
	long max=0;
	long m,n;
	long t1,t2,i;
	cin>>n;
	while(n){
		cin>>m;
		memset(a,0,1608);
		while(m){
			cin>>t1>>t2;
			t1=(t1+1)/2;
			t2=(t2+1)/2;
			if(t1<=t2){
				a[t1][0]++;
				a[t2][1]++;
			}else {
				a[t1][1]++;
				a[t2][0]++;
			}
			m--;
		}
		max=0;
		t1=0;
		for(i=1;i<=200;i++){
			t1+=a[i][0];
			if(t1>max)max=t1;
			t1-=a[i][1];
		}
		cout<<max*10<<endl;
		n--;
	}
	return 1;
}