#include <iostream>
using namespace std;

inline int result(int n){
	return ((n-1)*n)/2;
}

int main() {
	//init

	int count;
	cin>>count;
	while(count--){
		int n;
		cin>>n;
		cout<<result(n/2)+result(n-n/2)<<endl;
	}

	return 0;
}