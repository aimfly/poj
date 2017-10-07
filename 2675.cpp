#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
struct song{
	float a;
	int t;
};
bool bj(struct song &t1,struct song &t2){
	return t1.a<t2.a;
}
int main(){
	vector<struct song> d;
	int n;
	float l,f;
	struct song t1;
	while(cin>>n){
		d.clear();
		while(n){
			cin>>t1.t;
			cin>>l>>f;
			t1.a=l/f;
			d.push_back(t1);
			n--;
		}
		sort(d.begin(),d.end(),bj);
		cin>>n;
		cout<<d[n-1].t<<endl;
	}
	return 0;
}