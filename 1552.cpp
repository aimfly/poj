#include<iostream>
using namespace std;
int main(){
	int f[100];
	int n,i,ans;
	cin>>n;
	while(n!=-1){
		memset(f,0,400);
		ans=0;
		while(n){
			f[n]=1;
			cin>>n;
		}
		for(i=2;i<100;i+=2)if(f[i]&&f[i/2])ans++;
		cout<<ans<<endl;
		cin>>n;
	}
	return 0;
}