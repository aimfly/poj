#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
struct rec{
	int w,h;
};
bool bj(struct rec &t1,struct rec &t2){
	return t1.w>t2.w;
}
int main(){
	int n;
	int wt,ht3,ht4,ht1,ht2,i;
	struct rec t;
	int res;
	vector<struct rec> jx;
	cin>>n;
	while(n!=-1){
		jx.clear();
		while(n--){
			cin>>t.w>>t.h;
			jx.push_back(t);
		}
		sort(jx.begin(),jx.end(),bj);
		ht4=0;		
		ht3=jx[0].w;
		i=0;
		res=0;
		while(i<jx.size()){
			ht1=ht2=0;
			wt=jx[i].w;
			while(wt==jx[i].w&&i<jx.size()){
				if(jx[i].h>ht1){ht2=ht1;ht1=jx[i].h;}
				else if(jx[i].h>ht2) ht2=jx[i].h;
				i++;
			}
			if(ht2==0)ht2=ht3;
			res+=(ht2+ht1-ht3-ht4)*wt;
			ht3=ht1;
			ht4=ht2;
		}
		cout<<res<<endl;
		cin>>n;
	}
	return 0;
}