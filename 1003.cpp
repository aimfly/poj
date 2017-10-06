#include<iostream>
using namespace std;
int main(){
	double a,t;
	int i;
	cin>>a;
	while(a){
		i=2;
		t=0;
		while(t<a){
			t+=1/double(i);
			i++;
		}
		cout<<i-2<<" card(s)"<<endl;
		cin>>a;
	}
	return 0;
}