#include<iostream>
#include<map>
using namespace std;

map<int, int> res;

int cal_res(int idx)
{
	if(res[idx]!=0){
		return res[idx];
	}
	else{
		if(0==idx%2){
			res[idx]=1+cal_res(idx/2);
		}
		else{
			res[idx]=1+cal_res(idx*3+1);
		}
		return res[idx];
	}
}

int main()
{
	int a,b,max;
	int begin,end;
	int i=0;
	res[1]=1;
	for(i=1;i<10001;++i){
		cal_res(i);
	}
	while(cin>>a>>b){
		if(a>b){
			begin=b;
			end=a;
		}
		else{
			begin=a;
			end=b;
		}
		max=res[begin];
		for(i=begin+1;i<end+1;++i){
			if(res[i]>max){
				max=res[i];
			}
		}
		cout<<a<<' '<<b<<' '<<max<<endl;
	}
	return 0;
}