#include <iostream>
using namespace std;

int factor[12];

int pow5(int n){
	int result=1;
	for(int i=0;i<n;i++){
		result*=5;
	}
	return result;
}

int main() {
	//init
	for(int i=0;i<12;i++){
		factor[i]=pow5(12-i);
	}

	int count;
	cin>>count;
	while(count--){
        int n;
        int z=0;
        int last=0;
        cin>>n;
        for(int i=0;i<12;i++){
        	z+=(n/factor[i]-last)*(12-i);
        	last=n/factor[i];
        }
        cout<<z<<endl;
	}
	return 0;
}