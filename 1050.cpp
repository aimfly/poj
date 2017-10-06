#include<iostream>
using namespace std;
int a[100][100];
long b[100];
int main(){
	int n;
	int i,j,k;
	long maxs=-1270000;
	long t;
	long max;
	cin>>n;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)cin>>a[i][j];
	for(i=0;i<n;i++){
		memset(b,0,400);
		for(j=i;j<n;j++){
			for(k=0;k<n;k++)b[k]+=a[j][k];
			max=-12700;
			t=0;
			for(k=0;k<n;k++){
				if(t<0)t=b[k];
				else t+=b[k];
				if(t>max)max=t;
			}
			if(max>maxs)maxs=max;
		}
	}
	cout<<maxs<<endl;
	return 1;
}