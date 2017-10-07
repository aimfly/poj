#include<iostream>
using namespace std;
int a[256][9];
int qp[8][8];
int n,k;
int js(int c,int r,int k){
	int i;
	if(a[c][r]>=0)return a[c][r];
	else a[c][r]=0;
	if(k==0){
		a[c][r]=1;
		return 1;
	}
	if(r>=n)return 0;
	a[c][r]+=js(c,r+1,k);
	for(i=0;i<n;i++){
		if((c>>i)%2&&qp[r][n-i-1]){
			a[c][r]+=js(c&~(1<<i),r+1,k-1);
		}
	}
	return a[c][r];
}
int main(){
	char t;
	int i,j;
	int c;
	cin>>n>>k;
	while(n+1){
		memset(a,-1,9216);
		memset(qp,0,256);
		c=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++){
				cin>>t;
				if(t=='#')qp[i][j]=1;
			}
		for(i=0;i<n;i++)c=(c<<1)+1;
		cout<<js(c,0,k)<<endl;;
		cin>>n>>k;				
	}
	return 0;
}