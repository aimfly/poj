#include<iostream>
#include<math.h>
using namespace std;
const double pi=3.1415926;
int main(){
	int n,i,res;
	double x,y,a;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>x>>y;
		a=(x*x+y*y)*pi/2;
		res=ceil(a/50);
		cout<<"Property "<<i<<": This property will begin eroding in year "<<res<<'.'<<endl;
	}
	cout<<"END OF OUTPUT.";
	cin>>n;
	return 1;
}