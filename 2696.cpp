#include<iostream>
using namespace std;
int res[1001];
int main(){
	int n;
	int a,b,c,d,e,f,g,h,i;
	int t,k;
	cin>>n;
	while(n){
		memset(res,0,4004);
		cin>>a>>b>>c>>d>>e>>f>>g>>h>>i;
		res[0]=a;
		res[1]=b;
		res[2]=c;
		for(k=3;k<=i;k++){
			if(k%2){
				t=d*res[k-1]+e*res[k-2]-f*res[k-3];
				t=t%g;
				if(t<0)t+=g;
				res[k]=t;
			}else {
				t=f*res[k-1]-d*res[k-2]+e*res[k-3];
				t=t%h;
				if(t<0)t+=h;
				res[k]=t;
			}
		}
		cout<<res[i]<<endl;
		n--;
	}
	return 0;
}