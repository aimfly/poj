#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int row;
	vector<int> numbers;
	cin>>row;
	for(int i=0;i<(row+1)*row/2;i++)
	{
	    int tmp;
	    cin>>tmp;
	    numbers.push_back(tmp);
	}

	for(int i=row;i>1;i--){
	    for(int j=(i-2)*(i-1)/2;j<(i-2)*(i-1)/2+i-1;j++){
	        numbers[j]+=max(numbers[j+i-1],numbers[j+i]);
	    }
	}

	cout<<numbers[0]<<endl;

	return 0;
}