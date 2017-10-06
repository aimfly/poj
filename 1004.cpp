#include<iostream>
using namespace std;
int main(){
	double a,t;
	int i;
	for(a=0,i=0;i<12;i++){
		cin>>t;
		a+=t;
	}
	a=a/12;
	printf("$%.2f\n",a);
	return 1;
}