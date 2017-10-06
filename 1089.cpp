#include<iostream>
using namespace std;
long a[1000000][2];
int main(){
	long n;
	long t1,t2,i;
	memset(a,0,8000000);
	cin>>n;
	while(n){
		cin>>t1>>t2;
		a[t1][0]++;
		a[t2][1]++;
		n--;
	}
	t1=0;
	for(i=1;i<=1000000;i++){
		if(t1==0){
			if(a[i][0]>0){
							cout<<i<<' ';
							t1+=a[i][0]-a[i][1];
							if(t1==0)cout<<i<<endl;
			}
		}
		else {
			t1+=a[i][0]-a[i][1];
			if(t1==0)cout<<i<<endl;
		}
	}
	return 1;
}