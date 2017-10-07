#include<iostream>
using namespace std;
int js(int n){
	int t=0;
	int r=0;
	do{
		t=t*10+1;
		r++;
		t=t%n;
	}while(t);
	return r;
}
int main(){
	int n;
	while(cin>>n){
		cout<<js(n)<<endl;
	}
	return 0;
}