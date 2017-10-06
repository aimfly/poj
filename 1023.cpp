#include<iostream>
using namespace std;
int bit[64];
char cbit[64];
int type;
int count;
int pd(){
	int i;
	for(i=count-1;i>0;i--){
		if(bit[i]==2){bit[i-1]++;bit[i]=0;}
		else if(type==0){if(cbit[i]=='p'&&bit[i]==1)bit[i-1]++;}
		else {if(cbit[i]=='n'&&bit[i]==1)bit[i-1]++;}
	}
	if(type==0)
		if(cbit[0]=='p'&&bit[0]>0||bit[0]>1)return 0; 
				else return 1;
	else 
		if(cbit[0]=='n'&&bit[0]>0||bit[0]>1)return 0; 
				else return 1;
}
int main(){
	int n;
	__int64 num;
	int i;
	cin>>n;
	while(n){
		cin>>count;
		for(i=0;i<count;i++)cin>>cbit[i];
		scanf("%I64d",&num);
		if(num<0){type=0;num=-num;}
		else type=1;
		for(i=count-1;i>=0;i--){
			bit[i]=num%2;
			num=num/2;
		}
		if(num)cout<<"Impossible"<<endl;
		else if(pd()){
			for(i=0;i<count;i++)cout<<bit[i];
			cout<<endl;
		}
		else cout<<"Impossible"<<endl;
		n--;
	}
	return 1;
}