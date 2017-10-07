#include<iostream>
using namespace std;
int a[1501];
int main(){
	int i,j,k,min;
	int n=1;
	i=j=k=1;
	a[1]=1;
	while(n!=1500){
		n++;
		min=a[i]*2;
		if(a[j]*3<min)min=a[j]*3;
		if(a[k]*5<min)min=a[k]*5;
		if(min==a[i]*2)i++;
		if(min==a[j]*3)j++;
		if(min==a[k]*5)k++;
		a[n]=min;
	}
	cin>>n;
	while(n){
		cout<<a[n]<<endl;
		cin>>n;
	}
	return 0;
}