#include<iostream>
using namespace std;
int flag[1000000][2];
int choseB(long *a);
int choseA(long *a){
	long b[21];
	int i,j;
	unsigned int t=0;
	for(i=20;i>1;i--){
		t=t<<1;
		t+=a[i];
	}
	if(flag[t][0]==0||flag[t][0]==1)return flag[t][0];
	for(i=2;i<21;i++){
		if(a[i]==1){
			memcpy(b,a,84);
			b[i]=0;
			for(j=i+2;j<21;j++)
				if(b[j]==1&&b[j-i]==0)b[j]=0;
			if(choseB(b)==1){
				return 1;
				flag[t][0]=1;
			}
		}
	}
	flag[t][0]=0;
	return 0;
}
int choseB(long *a){
	long b[21];
	int i,j;
	unsigned int t=0;
	for(i=20;i>1;i--){
		t=t<<1;
		t+=a[i];
	}
	if(flag[t][1]==0||flag[t][1]==1)return flag[t][1];
	for(i=2;i<21;i++){
		if(a[i]==1){
			memcpy(b,a,84);
			b[i]=0;
			for(j=i+2;j<21;j++)
				if(b[j]==1&&b[j-i]==0)b[j]=0;
			if(choseA(b)==0){
				return 0;
				flag[t][1]=0;
			}
		}
	}
	flag[t][1]=1;
	return 1;
}
int main(){
	int n,m,t;
	long a[21];
	int i,j,f;
	long b[21];
	memset(flag,-1,8000000);
	n=1;
	cin>>m;
	while(m){
		memset(a,0,84);
		while(m){
			cin>>t;
			a[t]=1;
			m--;
		}
		cout<<"Test Case #"<<n<<endl;
		f=0;
		for(i=2;i<21;i++){
			if(a[i]==1){
				memcpy(b,a,84);
				b[i]=0;
				for(j=i+2;j<21;j++)
					if(b[j]==1&&b[j-i]==0)b[j]=0;
				if(choseB(b)==1){
					if(!f){
						f=1;
						cout<<"The winning moves are: "<<i;
					}else cout<<' '<<i;
				}
			}
		}
		if(!f)cout<<"There's no winning move."<<endl<<endl;
		else cout<<endl<<endl;
		cin>>m;
		n++;
	}
	return 0;
}