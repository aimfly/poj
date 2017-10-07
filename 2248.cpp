#include<iostream>
using namespace std;
int a[50];
int r[50];
int m=50;
void dfs(int n,int k){
	int i;
	if(a[k]==n&&k<m){m=k;memcpy(r,a,200);return;}
	if(a[k]>n||k>=m)return;
	for(i=k;i>=0;i--){
		a[k+1]=a[k]+a[i];
		dfs(n,k+1);
	}
	return;
}
int main(){
	int n;
	int i;
	cin>>n;
	a[0]=1;
	while(n){
		m=50;
		dfs(n,0);
		for(i=0;i<=m;i++)cout<<r[i]<<' ';
		cout<<endl;
		cin>>n;
	}
	return 0;
}