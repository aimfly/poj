#include<iostream>
using namespace std;
int main(){
	int p,e,i,d;
	int res,n;
	n=1;
	cin>>p>>e>>i>>d;
	while(p!=-1){
		if(p==e&&e==i)res=21252-d;
		else{
		while(p!=e||e!=i)
		{
			if(p<=e&&p<=i)p+=23;
			else if(e<=p&&e<=i)e+=28;
			else i+=33;
		}
		if(p<=d)res=p+21252-d;else res=p-d;
		}
		if(res>21252)res-=21252;
		cout<<"Case "<<n<<": the next triple peak occurs in "<<res<<" days."<<endl;
		n++;
		cin>>p>>e>>i>>d;
	}
	return 1;
}