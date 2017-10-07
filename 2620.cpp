#include<iostream>
#include<vector>
using namespace std;
struct zb{
	int x,y;
};
int main(){
	int m;
	int x,y;
	int i,j;
	vector<struct zb> r;
	int a[5001]={0};
	struct zb z;
	int no=0;
	cin>>m>>x>>y;
	i=j=0;
	while(x||y){
		if(y<=0||x>=m){cin>>x>>y;continue;}
		if(x<=0){
			if(y>j){
				j=y;
				i=x;
			}}
		else if(y>a[x])a[x]=y;
		cin>>x>>y;
	}
	z.x=i;
	z.y=j;
	r.push_back(z);
	i=1;
	if(j==0)no=1;
	else
		while(j<m){
			x=y=0;
			while(i<=j){
				if(a[i]>j)
					if(a[i]>y){y=a[i];x=i;}
				i++;
			}
			if(y==0){no=1;break;}
			z.x=x;
			z.y=y;
			r.push_back(z);
			i=j+1;
			j=y;
		}
	if(no)cout<<"No solution"<<endl;
	else {
		cout<<r.size()<<endl;
		for(i=0;i<r.size();i++){
			cout<<r[i].x<<' '<<r[i].y<<endl;
		}
	}
	return 0;
}